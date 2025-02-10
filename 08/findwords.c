#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static const char* cmdname;

static const char* default_word_files[] = {
   "/usr/share/dict/words", /* Linux, MacOS */
   "/usr/share/lib/dict/words", /* Solaris */
   0, /* terminate list */
};

static void die(const char* msg) {
   fprintf(stderr, "%s: ", cmdname);
   if (errno) {
      perror(msg);
   } else {
      fprintf(stderr, "%s\n", msg);
   }
   exit(1);
}

static void usage() {
   fprintf(stderr, "Usage: %s {-w wordlist} file...\n", cmdname);
   exit(1);
}

static FILE* open_file(const char* filename) {
   if (strcmp(filename, "-") == 0) {
      return stdin;
   }
   FILE* fp = fopen(filename, "r");
   if (!fp) die(filename);
   return fp;
}

static FILE* try_open_file(const char* filename) {
   if (strcmp(filename, "-") == 0) {
      return stdin;
   }
   FILE* fp = fopen(filename, "r");
   return fp;
}

static void close_file(FILE* fp) {
   if (fp != stdin) fclose(fp);
}

static char* readline(FILE* fp) {
   size_t len = 0;
   size_t allocated = 8;
   char* buf = malloc(allocated);
   if (!buf) return 0;

   int ch;
   while ((ch = getc(fp)) != EOF && ch != '\n') {
      /* make sure that we have always space
         for the current byte ch and a terminating null-byte */
      if (len + 1 == allocated) {
         allocated = allocated * 2 + 8;
         char* newbuf = realloc(buf, allocated);
         if (!newbuf) {
            free(buf); return 0;
         }
         buf = newbuf;
      }
      buf[len++] = ch;
   }
   if (len || ch != EOF) {
      buf[len] = 0;
      if (len + 1 < allocated) {
         /* release no longer needed extra space */
         buf = realloc(buf, len+1);
      }
      return buf;
   } else {
      free(buf);
      return 0;
   }
}

static void make_lower(char* word) {
   for (char* cp = word; *cp; ++cp) {
      if (isupper(*cp)) {
         *cp = tolower(*cp);
      }
   }
}

typedef uint64_t hash_value;
struct hash_entry {
   hash_value hashval;
   char* word;
   struct hash_entry* next;
};
typedef struct {
   size_t size;
   struct hash_entry** bucket;
} hash_table;

static hash_value get_hash_value(const char* word) {
   /* FNV hash function for 64 bit */
   hash_value val = 14695981039346656037ull;
   int ch;
   while ((ch = *word++)) {
      val = (val ^ ch) * 1099511628211ull;
   }
   return val;
}

static void init_hash_table(hash_table* ht, size_t size) {
   ht->size = size;
   ht->bucket = calloc(size, sizeof(struct hash_entry*));
   if (!ht->bucket) {
      die("calloc");
   }
}

/* return true if word has been found in ht;
   otherwise the word is inserted and false is returned */
static bool hash_search(hash_table* ht, char* word) {
   hash_value hash = get_hash_value(word);
   size_t index = hash % ht->size;
   for (struct hash_entry* p = ht->bucket[index]; p; p = p->next) {
      if (p->hashval == hash && strcmp(word, p->word) == 0) {
	 return true;
      }
   }
   struct hash_entry* entry = malloc(sizeof(struct hash_entry));
   if (!entry) {
      die("malloc");
   }
   char* wordp = strdup(word);
   if (!wordp) {
      die("strdup");
   }
   *entry = (struct hash_entry) {
      .hashval = hash, 
      .word = wordp,
      .next = ht->bucket[index],
   };
   ht->bucket[index] = entry;
   return false;
}

static void release_hash_table(hash_table* ht) {
   for (size_t index = 0; index < ht->size; ++index) {
      struct hash_entry* p = ht->bucket[index];
      while (p) {
	 struct hash_entry* pp = p;
	 p = p->next;
	 free(pp->word); free(pp);
      }
   }
   free(ht->bucket); ht->size = 0;
}

static bool load_word_list(hash_table* ht, const char* filename) {
   FILE* fp = try_open_file(filename);
   if (!fp) return false;
   char* line;
   while ((line = readline(fp))) {
      make_lower(line);
      hash_search(ht, line);
      free(line);
   }
   close_file(fp);
   return true;
}

static void check_word(hash_table* ht, char* word) {
   make_lower(word);
   if (!hash_search(ht, word)) {
      puts(word);
   }
}

static void process_input(hash_table* ht, const char* filename) {
   FILE* fp = open_file(filename);
   char* line;
   while ((line = readline(fp))) {
      char* word = 0;
      for (char* cp = line; *cp; ++cp) {
         if (word) {
            if (!isalpha(*cp) && *cp != '\'') {
               *cp = 0; check_word(ht, word); word = 0;
            }
         } else if (isalpha(*cp)) {
            word = cp;
         }
      }
      if (word) check_word(ht, word);
      free(line);
   }
   close_file(fp);
}

int main(int argc, char* argv[]) {
   cmdname = *argv;
   char* cp = strrchr(cmdname, '/');
   if (cp) {
      /* set cmdname to its basename */
      cmdname = cp + 1; /* behind '/' */
   }
   unsigned word_lists = 0;

   hash_table ht;
   init_hash_table(&ht, 1ull << 18);

   /* process options */
   opterr = 0; /* disable error messages by getopt */
   int option;
   while ((option = getopt(argc, argv, ":w:")) != -1) {
      switch (option) {
         case 'w':
            if (!load_word_list(&ht, optarg)) {
	       die(optarg);
	    }
	    ++word_lists;
            break;
         case ':':
            fprintf(stderr, "%s: option '-%c' requires an operand\n",
               cmdname, optopt);
            usage();
         default:
            fprintf(stderr, "%s: unknown option '-%c'\n", cmdname, optopt);
            usage();
      }
   }
   argc -= optind; argv += optind; /* skip options processed by getopt() */

   if (word_lists == 0) {
      bool found = false;
      for (const char** dwfp = default_word_files; *dwfp; ++dwfp) {
	 if (load_word_list(&ht, *dwfp)) {
            found = true; break;
         }
      }
      if (!found) {
         fprintf(stderr, "%s: no default dictionary found!\n", cmdname);
         exit(1);
      }
   }

   if (argc == 0) {
      process_input(&ht, "-");
   } else {
      while (argc > 0) {
         process_input(&ht, *argv++); --argc;
      }
   }
   release_hash_table(&ht);
}


#include <stdio.h>
#include <stdlib.h>

int main() {
   puts("Wie viele Reihen gibt es im Spiel?");

   unsigned int reihen;
   if (scanf("%u", &reihen) != 1) {
      exit(2);
   }
   unsigned int nim = 0;
   for (int i = 1; i <= reihen; i++) {
      printf("Anzahl in Reihe %d?\n", i);
      unsigned int anzahl;
      if (scanf("%u", &anzahl) != 1) {
         exit(2);
      }
      nim ^= anzahl % 4;
   }

   if (nim == 0) {
      puts("\nDas ist eine Verluststellung!");
      return 1;
   } else {
      printf("\nDas ist eine Gewinnstellung mit Nim-Summe %u!\n", nim);
      return 0;
   }
}

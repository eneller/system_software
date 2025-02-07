#include <stdio.h>
#include <stdint.h>

int main() {
   char c;
   int i;
   signed short ss;
   unsigned long ul;
   signed long long sll;
   uint16_t ui16;
   int64_t i64;

   printf("Ein char ist hier %zu Bytes groß.\n", sizeof(c));
   printf("Ein int ist hier %zu Bytes groß.\n", sizeof(i));
   printf("Ein signed short ist hier %zu Bytes groß.\n", sizeof(ss));
   printf("Ein unsigned long ist hier %zu Bytes groß.\n", sizeof(ul));
   printf("Ein signed long long  ist hier %zu Bytes groß.\n", sizeof(sll));
   printf("Ein uint32_t ist hier %zu Bytes groß.\n", sizeof(ui16));
   printf("Ein int64_t ist hier %zu Bytes groß.\n", sizeof(i64));
}

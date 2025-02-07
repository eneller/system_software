#include <stdio.h>
#include <stdint.h>

int main() {
   uint8_t a = 7;
   uint8_t b = 255;

   uint8_t c = a - b;
   printf("%hhu\n", c);
}


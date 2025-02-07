#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

void print_kegel(unsigned long kegel, int maxkegel){
  unsigned char bit;
  bool started = false;
    for(int i=maxkegel; i>=0; i--){
      bit = (kegel >> i) & 1;
      if (bit == 1 || started){
        started = true;
        printf("%d", bit);
      }
    }
  printf("\n");
}
int main() {
   srand(time(NULL) ^getpid());
   unsigned long kegel =0;
   // wie viele kegel stehen?
   int maxkegel = 32;//(sizeof(kegel) * 8 )
   int kegelzahl= rand() % maxkegel;
   for (int i =0; i < kegelzahl; i++){
     kegel = kegel << 1;
     kegel = kegel | 1;
   }
   print_kegel(kegel, maxkegel);
   // Zug
   int schuss =0;
   while(true){

     if (scanf("%d", &schuss) != 1) {
           exit(2);
     }
   }
   //TODO print won/lost

}


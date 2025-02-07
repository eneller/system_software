#include <stdio.h>

int main(){
  int number = 0;
  printf("Nummer eingeben: ");
  scanf("%d", &number);
  unsigned char bit;
    for(int i=8*sizeof(number)-1; i>=0; i--){
      bit = (number >> i) & 1;
      printf("%d", bit);
    }
  printf("\n");
}

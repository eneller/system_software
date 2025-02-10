#include <stdio.h>
#include <stdbool.h>

void print_binary(int number){
  bool numberstarted = false;
  unsigned char bit;
  printf("0b");
    for(int i=8*sizeof(number)-1; i>=0; i--){
      bit = (number >> i) & 1;
      if (bit == 0 && !numberstarted){;}
      else {
        printf("%d", bit);
        numberstarted = true;
      }
    }

}

void print_binary_scan(){
  int number = 0;
  printf("Nummer eingeben: ");
  scanf("%d", &number);
  print_binary(number);
  printf("\n");
}

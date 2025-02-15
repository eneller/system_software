#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
   int repetitions;
   printf("Wie oft soll gewürfelt werden?\n");
   switch(scanf("%d", &repetitions)){
      case EOF:
         printf("Failed");
         break;
      case 1: break;// the expected value
      default: printf("Could not read integer");
   }
   // Zufallszahlengenerator mit aktueller Zeit initialisieren
   srand(time(NULL) ^ getpid());

   int sum =0;
   int wuerfel;
   for (int i = 1; i <= repetitions; i++){
      wuerfel = rand() % 6 +1;
      sum = sum + wuerfel;
      printf("Würfel Nr. %d zeigt %d\n", i, wuerfel);
   }
   printf("Würfe: %d\n", repetitions);
   printf("Summe: %d\n", sum);
   printf("Durchschnittswert: %f\n", (float)sum/repetitions);
}
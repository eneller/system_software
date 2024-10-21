#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
   int repetitions = 3;
   printf("Wie oft soll gewürfelt werden?\n");
   scanf("%d", &repetitions);
   // Zufallszahlengenerator mit aktueller Zeit initialisieren
   srand(time(NULL) ^ getpid());

   float sum =0;
   int wuerfel;
   for (int i = 1; i <= repetitions; i++){
      wuerfel = rand() % 6 +1;
      sum = sum + wuerfel;
      printf("Würfel Nr. %d zeigt %d\n", i, wuerfel);
   }
   printf("Durchschnittswert über %d Würfe ist %f\n", repetitions, sum/repetitions);
}
#include <stdio.h>
int main(){
    int zahl = 1234;
    for (;zahl>=1;zahl/=10){
        printf("%d", zahl%10);
    }
}
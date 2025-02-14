#include <stdio.h>

#include "../binary.c"


/*
C does not feature a special exponentiation operator '**' but helper functions exist in standard libraries.
*/
int main(){
    unsigned long long n, m, result;
    n = m = 3;
    result = n;
    for(;m>0;m--){
        result *=n;
    }
    printf("%llu\n", result);
}
#include <stdio.h>

typedef struct {
    double real;
    double img;
} Complex;

Complex* create_complex(double real, double img){
    Complex c;
    c.real = real;
    c.img = img;
    return &c;
}
int main(){
    Complex*  c = create_complex(3,4);    
    printf("%lf", c->real);
}
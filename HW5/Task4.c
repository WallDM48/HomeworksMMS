#include<stdio.h>
#include<math.h> 

int quadEq(double a, double b, double c, double* x1, double* x2){
    double D = b*b - 4*a*c;
    if(D < 0){
        return -1;
    }
    *x1 = (-b + sqrt(D))/(2*a);
    *x2 = (-b - sqrt(D))/(2*a);
    return 0;
}


int main(){

    double a, b, c, x1, x2;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){

        if(quadEq(a,b,c,&x1,&x2)){
            puts("There is no real roots\n");
        }
        if(!quadEq(a,b,c,&x1,&x2)){
            printf("x1 = %.2lf\nx2 = %.2lf\n", x1, x2);
        }
    }

    return 0;
}
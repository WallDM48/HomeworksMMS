#include <stdio.h>
#include <math.h>

int triangle(double a, double b, double c, double* S, double *P){
    if (a < 0 || b < 0 || c < 0 ){
        return -1;
    }
    if(a + b < c || a + c < b || b + c < a || fabs(a - b)  > c || fabs(b - c) > a || fabs(a - c) > b ){
        return -1;
    }
    *P = a + b + c ;
    double p = *P/2;
    *S = sqrt(p*(p - a)*(p - b)*(p - c));
    return 0;

}

int main(){
    double a, b, c, S, P;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){

    if(triangle(a,b,c,&S,&P)){
        puts("Invalid sizes\n");
    }
    if(!triangle(a,b,c,&S,&P)){
        printf("P = %.2lf and S = %.2lf\n",P, S);
    }
    }
    return 0;
}
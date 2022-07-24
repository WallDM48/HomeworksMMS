#include<stdio.h>

double calcSin(double* x) 
{
double sum;
double fa;
double pow;
sum = 0.0;
for(int i = 0; i <= 20; i++)
{
fa = 1.0;
pow = 1.0;
for(int j = 1; j <= 2*i+1; j++)
{
fa *= j;
pow *= *x;
}
sum += ((i%2?-1.0:1.0)/fa)*pow;
}
return sum;
}

int main(){
    double degr;

    scanf("%lf",&degr);

    printf("Sin(%lf) = %lf\n",degr,calcSin(&degr));

    return 0;
}
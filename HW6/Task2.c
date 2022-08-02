#include <stdio.h>

#define n 20

double sin(double x) 
{
double sum;
double fa;
double pow;
sum = 0.0;
for(int i = 0; i <= n; i++)
{
fa = 1.0;
pow = 1.0;
for(int j = 1; j <= 2*i+1; j++)
{
fa *= j;
pow *= x;
}
sum += ((i%2?-1.0:1.0)/fa)*pow;
}
return sum;
}

int main()
{
double angle;
double x;
printf("Enter the degrees: \n");
scanf("%lf", &angle);
x = (3.1415926535897931*angle)/180.0; // calculate the radians

printf("sinus(%.2lf): %.3lf\n",angle,sin(x));
return 0;
}


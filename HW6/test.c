#include <stdio.h>
#define n 20


double sin(double);
double cos(double);
int main(int argc,char **argv)
{
int a,b;
double m;
double x;
printf(“Enter the degrees: “);
scanf(“%lf”, &m);
x = (3.1415926535897931*m)/180.0; //To calculate the rad

printf(“The rad of %0.2f: %f\n”,m, x);
//a=sin(x); //To call the sine function
//b=cos(x); //To call the cosine function
printf(“sin(%0.2lf):%lf\n”,m,sin(x));
printf(“cos(%0.2lf):%lf\n”,m,cos(x));
return 0;
}
double sin(double x) //sin calculation
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

double cos(double x) //cosine calculation
{
double sum;
double fa;
double pow;
sum = 0.0;
for(int i = 0; i <= n; i++)
{
fa = 1.0;
pow = 1.0;
for(int j = 1; j <= 2*i; j++)
{
fa *= j;
pow *= x;
}
sum += ((i%2?-1.0:1.0)/fa)*pow;
}
return sum;
}

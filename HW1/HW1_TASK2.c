#include<stdio.h>
#include<math.h>

#define PI 3.14

int main(){
    double r,l,h;
    puts("Enter the radius, lenght and height");
    scanf("%lf %lf %lf",&r, &l, &h);

    double volume1 = r*r*PI*h;
    printf("The volume 1 is : %.2lf\n",volume1);

    double volume2= (acos((r-h)/r)*r*r-(r-h)*sqrt(2*r*h-h*h))*l;

    printf("The volume 2 is : %.2lf\n",volume1);
    return 0;
}
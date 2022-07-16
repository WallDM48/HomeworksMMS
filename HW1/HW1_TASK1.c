#include<stdio.h>
#include<math.h>

int main(){
    double BMI,mass,height;
    scanf("%lf %lf", &mass,&height);
    BMI=mass/(pow(height,2));

    printf("Your BMI index is : %lf\n",BMI);

    double BMI2 = 1.3*mass/(pow(height,2.5));

    printf("Your BMI index accordin to Nick Trefeten is : %lf\n",BMI2);
    return 0;
} 
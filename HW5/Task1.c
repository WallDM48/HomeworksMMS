#include<stdio.h>

int main(){
    double a,b;
    char c;

    while(scanf("%lf %c %lf",&a,&c,&b)!= EOF){
        
    switch (c)
    {
    case '+':
        printf("%.3lf\n",a+b);
        break;
    case '-':
        printf("%.3lf\n",a-b);
        break;
    case '*':
        printf("%.3lf\n",a*b);
        break;
    case '/':
        printf("%.3lf\n",a/b);
        break;
    default:
        break;
        
    }
    }
    return 0;
}
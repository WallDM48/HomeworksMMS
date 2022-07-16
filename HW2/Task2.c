#include<stdio.h>

int main(){
    unsigned a,b,c;
    scanf("%d %d %d",&a, &b, &c);
    if(a>1 || b>1 || c>1){
        puts("Error! You are entered incorrect number");
    }
    else {
    int d = (a^b)^c;
    printf("%d\n",d);
    }

    return 0;
}
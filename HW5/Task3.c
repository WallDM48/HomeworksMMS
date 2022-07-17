#include <stdio.h>

int rectInfo(double w, double h, double* P, double *S){
    if (w <= 0 || h <= 0){
        return -1;
    }
    *P = (w + h) * 2;
    *S = w * h;
    return 0;
}

int main(){
    double w, h, S, P;
    while (scanf("%lf %lf", &w, &h) != EOF){
        if(!rectInfo(w, h, &P, &S)){
            printf("The perimeter is = %lf and the S is = %lf\n", P, S);
        } else {
            printf("Invalid rectangle size!\n");
        }
    }
    return 0;
}

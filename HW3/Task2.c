#include<stdio.h>
#include<math.h>
#define EPS1 0.00001f
#define EPS2 0.0001f
#define EPS3 0.001f
#define EPS4 0.01f

void simpleComp(float a, float b){
    if(a==b){
        printf("a==b\n");
    }
    else {    
    printf("a!=b\n");
    }
}
void epsComp(float a, float b,float c){
    if(fabs(a-b)<c){
         printf("a==b\n");
    }
    else {    
    printf("a!=b\n");
    }
}


int main(){
    float a = 54.0f;
    float b = 0.54f;
    for(int i = 0; i<99; i++){

        b +=0.54f;
    }
    simpleComp(a,b);
    puts("\n");
    epsComp(a,b,EPS1);
    puts("\n");
    epsComp(a,b,EPS2);
    puts("\n");
    epsComp(a,b,EPS3);
    puts("\n");
    epsComp(a,b,EPS4);
    puts("\n");
    printf("%f %f\n",a,b);
    // the floating point numbers must be compare via constant(eps)
    // the biggers is eps , the smallest is the mistake by the 2 numbers
    


    return 0;
}
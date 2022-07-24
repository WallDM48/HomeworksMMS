#include<stdio.h>
#include<stdint.h>


#define TINT 1
#define TDOUBLE 2 
#define TCHAR 3
#define TFLOAT 4
#define TUINT_8T 5
#define TUINT_16T 6
#define TUINT_32T 7
#define TUINT_64T 8

void printValue(const void* valuePtr, uint8_t flag){

 switch (flag)
 {
 case 1:
    printf("%d", *(int*)valuePtr);
    break;
case 2:
    printf("%lf", *(double*)valuePtr);
    break;
case 3:
    printf("%c", *(char*)valuePtr);
    break;
case 4:
    printf("%f", *(float*)valuePtr);
    break;
case 5:
    printf("%u", *(uint8_t*)valuePtr);
    break;
case 6:
    printf("%u", *(uint16_t*)valuePtr);
    break;
case 7:
    printf("%u", *(uint32_t*)valuePtr);
    break;
case 8:
    printf("%lu", *(uint64_t*)valuePtr);
    break;
 
 default:
    break;
 }
}

int main(){
    int n = 1;
    double PI= 3.14;
    char c = 'a';
    uint64_t d = 66;
    printValue(&n,TINT);
    puts("\n");
    printValue(&PI,TDOUBLE);
    puts("\n");
    printValue(&c,TCHAR);
    puts("\n");
    printValue(&d,TUINT_64T);

    return 0;
}
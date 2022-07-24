#include<stdio.h>
#include<stdarg.h>

unsigned bitsNCount(unsigned count, unsigned bitscnt, ...){
 int sum = 0;
 int c =0;
    va_list args;
    va_start(args, bitscnt);
    for (int i = 0; i < count; i++){
        unsigned a = va_arg(args,int);
        for(int j=0; j< sizeof(unsigned)*__CHAR_BIT__; j++ ){
            sum += !!(a & (1ull << j));
        }
       // printf("%d\n",sum);
        if(sum == bitscnt){
            c++;
        }
        sum =0 ;
    }
    va_end(args);
    return c;
}


int main(){
    printf("%u\n",bitsNCount(4, 2, 0x0a, 0xff, 0, 1));
    printf("%u\n",bitsNCount(3, 8, 0xff, 0x13f1,0xaaaa));
    return 0;
}

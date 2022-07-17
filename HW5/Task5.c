#include <stdio.h>
#include<stdint.h>

unsigned onesCount(uint64_t* mask){
    int num =0;
    for(int i =0; i<64;i++){
        num += !!(*mask&(*mask<<i));
    }
    return num;
}

int main(){
    uint64_t mask = 26;

    printf("The ones in mask are : %d\n",onesCount(&mask));
    return 0;
}
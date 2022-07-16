#include <stdio.h>

void swap(int*, int*);

int main(void)
{
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Before swap: Num1 = %d, Num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swap: Num1 = %d, Num2 = %d\n", num1, num2);
    return 0;
}
 // operation in terminal:
 /* gcc -E program.c -o pr.i
    gcc -S pr.i -o pr.s
    gcc -c pr.s -o pr.o
    gcc -E swap.c -o sw.i
    gcc -S sw.i -o sw.s
    gcc -c sw.s -o sw.o
    gcc pr.o sw.o -o program



#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a);
}

int secondMax(int* arr, int n){
    qsort(arr,n,sizeof(int),cmpfunc);
   
    return arr[1];
}



int main () {
   int n;
   scanf("%d",&n);


   int arr[n];
   for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);

   }
   printf("%d\n",secondMax(arr,n));
  
  
   return 0;
}
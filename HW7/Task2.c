#include <stdio.h>

int sumOfArr(int* arr, int n){
   
   int sum =0;
   int a;
    for(int i = 0; i < n; i++){
        a = arr[i];
        {do{
             sum += a%10;
             a = a%10;
        }
        while(arr[i] != 0);}
        
     }
    
    return sum;
}



int main () {
   int n;
   scanf("%d",&n);


   int arr[n];
   for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);

   }

   printf("%d\n",sumOfArr(arr,n));

  
   return 0;
}
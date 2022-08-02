#include <stdio.h>

int sumOfArr(int* arr, int n){
   
   int sum =0;
    for(int i = 0; i < n; i++){
        do
        {
         if(arr[i] < 10){
            sum += arr[i];
         }
         else{         
         sum =sum + arr[i] % 10;}
         arr[i] = arr[i] / 10;
        } while (arr[i] !=0);
        
     }
    
    return sum;
}
void fillArr(int *arr, int n){
   puts("Enter the elements of array");
    for(int i = 0; i < n; i++){
      scanf("%d",&arr[i]);
     
    }
}


int main () {
   int size;

   puts("Enter the size of array");
   scanf("%d",&size);

   int arr[size];

   fillArr(arr,size);
   
   printf("The sum of digits is :%d\n",sumOfArr(arr,size));

  
   return 0;
}
#include<stdio.h>
#include<stdint.h>
int main(void)
{
    uint64_t attendance = 0;
    int option;
    int bit;
    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        scanf("%d", &option);
         if(option==5 )
        {
            break;
        }
        
        if (option == 1)
        {   
            puts("Which bit you want to modify\n");
            scanf("%d",&bit);
             attendance |=(1ULL<<bit);
        }
        else if (option == 2)
        {
            puts("Which bit you want to modify\n");
        scanf("%d",&bit);
            attendance &=~(1ULL<<bit);
        }
        else if (option == 3)
        {
           
           for(int b=sizeof(attendance)*__CHAR_BIT__-1;b>=0;b--){

        printf("%d",!!(attendance&(1ULL<<b)));
    }
        }
        else if(option == 4)
        {   puts("Which bit you want to modify\n");
            scanf("%d",&bit);
            attendance^=(1ULL<<bit);
        }
       
    puts("\n");
    }
    
    return 0;
}
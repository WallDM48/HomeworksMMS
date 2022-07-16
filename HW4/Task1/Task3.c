#include <stdio.h>
#include <string.h>
 
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 

int toDeci(char *str, int base)
{
    int len = strlen(str);
    int power = 1; 
    int num = 0;  
    int i;
 
    for (i = len - 1; i >= 0; i--)
    {
        
        if (val(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
 
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}
 char valC(int c)
{
    char a = c + '0';
    if(c<0 && c >35){
        return 1;
    }
    if (c <=  9 && c >= 0)
        return (char)a;
    else if(c >9 && c<=35){
        return (char)a + 7;
    }
}


void toAny(int decN, int base){
    int num;
    char str[255];
    int i=0;  
    do{
            num = decN % base;
            if(num == 0){
                str[i] = '0';
            }else{
            str[i] = valC(num);
            }
        decN = decN / base ;
        
        i++;   
    }while(decN !=0);

    for(int i = strlen(str); i >= 0; i--){
        printf("%c",str[i]);
    }
}



int main()
{
    char str[255]={"AR20"};
    puts("Enter the number you want to convert(letters must be uppercase):\n");
    scanf("%s",str);
    
    int baseIn,baseTo;
    puts("Enter the base from which you want to convert(2-36):\n");
    scanf("%d",&baseIn);
    if(baseIn < 2 || baseIn > 36){
        puts("INVALID BASE!\n");
        goto out;
    }

    if(toDeci(str,baseIn) == -1)
    {
        goto out;
    }
    
    int decNum = toDeci(str,baseIn);
    
    puts("Enter the base you want convert to:\n");
    scanf("%d",&baseTo);
    if(baseTo < 2 || baseTo > 36){
        puts("INVALID BASE!\n");
        goto out;
    }

    toAny(decNum,baseTo);
    out:
    puts("\n");
    
    
    return 0;
}
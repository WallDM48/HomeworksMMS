#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define COUNT 5

typedef struct Book{
    char title[20];
    char author[20];
    int pages;
    double price;
}Book;

int randInit(int min, int max){
    return min + rand()%(max -min +1);
}

void rand_Init_Book(Book *b){

    int len =randInit(10,20); 
    char buf [] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    b->title[0] = buf[26 + rand()%26];
    for(int i =1 ; i < len-1 ;i++)
    {
        b->title[i] = buf[rand()%53];   
    }
    b->title[len] ='\0';
    len = randInit(10,20); 
    b->author[0] = buf[26 + rand()%26];
    for(int i =1 ; i < len-1;i++)
    {
        b->author[i] = buf[rand()%53];
    }
    b->author[len] = '\0';
    b->pages = randInit(5,2000);
    b->price = (100 + rand()%(10000-100))/100.;    



}

void print_struct(Book *b){
    printf(" Title: %s Author: %s  Pages: %d  Price: %.2lf\n",b->title,b->author,b->pages,b->price);
}

int main(int argc, char**argv){

    srand(time(NULL));
    
    
    Book *books = malloc(COUNT*sizeof(Book));
    for (int i = 0; i < COUNT; i++)
    {
        rand_Init_Book(books+i);
        print_struct(books+i);
    }
    

    FILE *fb = fopen(argv[1],"wb");
    if(!fb){
        fprintf(stderr,"Cannot open file!\n");
        exit(EXIT_FAILURE);
    }

    if(fwrite(books,sizeof(Book),COUNT,fb) != COUNT){
       perror("writing error!\n");
    }

    fclose(fb);
    free(books);
 
    return 0;
}
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
    for(int i =0 ; i < len-1 ;i++)
    {
        b->title[i] = buf[rand()%53];   
    }
    b->title[len] ='\0';
    len = randInit(10,20); 
    for(int i =0 ; i < len-1;i++)
    {
        b->author[i] = buf[rand()%53];
    }
    b->author[len] = '\0';
    b->pages = randInit(5,2000);
    b->price = (100 + rand()%(10000-100))/100.;    



}

void print_struct(Book *b){
    int i =0 ;
    printf(" Title: %s Author: %s  Pages: %d  Price: %.2lf\n",b->title,b->author,b->pages,b->price);
}

int main(int argc, char**argv){

    srand(time(NULL));
    Book *books = malloc(COUNT*sizeof(Book));
    for (int i = 0; i < COUNT; i++)
    {
        rand_Init_Book(books+i);
    }
    
    
 
    FILE *f = fopen(argv[1],"wb");
    if(!f){
        fprintf(stderr,"Cannot open file!\n");
        exit(EXIT_FAILURE);
    }

    //fwrite(books,sizeof(books),1,f);
    
    for (int i = 0; i < COUNT; i++)
    {
         print_struct(books+i);
         fwrite(books+i,sizeof(books),1,f);
    }
   
    
    free(books);
    fclose(f);
 
    return 0;
}
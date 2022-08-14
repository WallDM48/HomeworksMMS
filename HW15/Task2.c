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

typedef struct Node{
    Book b;
    Node *next;
}Node;

void read(Node **head, FILE *f){
    while(fread())
}

int main(){

    FILE *fr = fopen("books","rb");
    Node *n = malloc(sizeof(Node));


    fclose(fr);
    return 0;
}
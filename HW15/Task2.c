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
    struct Node *next;
}Node;

Book *read_book( FILE *f){
   Book *book_data = malloc(sizeof(Book)*COUNT);
   if(!book_data){
    perror("malloc failed!\n");
    exit(-1);
   }
   fread(book_data,sizeof(Book),COUNT,f);

   return book_data;

}

void push_back(Node **head, Book *b) {
    Node *new_node = malloc(sizeof(Node));
    if(!new_node) {
        perror("Push_back: Could not malloc\n");
        exit(-1);
    }
    strcpy(new_node->b.author,b->author);
    strcpy(new_node->b.title,b->title);
    new_node->b.pages = b->pages;
    new_node->b.price = b->price;
    new_node -> next = NULL;

    // If linked list is empty - then adress of first element is NULL
    if(*head == NULL) {
        *head = new_node;
        return;
    }

    Node *last_node = *head;
    while(last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node -> next = new_node;
}

int comapre_name(const void *p1, const void *p2){
    const Book *name1 = p1;
    const Book *name2 = p2;

    int res = strcmp(name1->title,name2->title);
    

    return res;


}

void print_ll(Node *head) {
    if(!head) {
        printf("Empty linked list\n");
        return;
    }
    Node *curNode = head;
    while(curNode) {
        printf("addr: %p,  Title: %20s,  Author: %20s,  Pages: %4d,  Price: %.2lf,  next: %p\n",
            curNode, curNode->b.title,curNode->b.author,curNode->b.pages,curNode->b.price,curNode->next);
        curNode = curNode->next;
    }
}

int main(int argc, char **argv){

    FILE *fr = fopen(argv[1],"rb");
    FILE *fw = fopen(argv[2],"wb");
    Node *n = malloc(sizeof(Node));
    Book *b;
    n = NULL;
    b = read_book(fr);

    qsort(b,COUNT,sizeof(Book),comapre_name);


    for (int i = 0; i < COUNT ; i++)
    {
        push_back(&n,b+i);
    }
    
    print_ll(n);

    if(fwrite(n,sizeof(Node),COUNT,fw) != COUNT){
        perror("WRITING ERROR!\n");
        exit(-1);
    }

    free(n);
    free(b);
    fclose(fr);
    fclose(fw);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

struct Node{
    
    int number;
    struct Node* next;
};// Linked list 

pthread_mutex_t mutex;// The mutex 
pthread_cond_t cond;// Condition variables, , Used to control consumers 
struct Node *head = NULL;// Chain header node pointer 

void *producer(void *arg);// producer 
void *consumer(void *arg);// consumer 

void Init(pthread_t *ptid, pthread_t *ctid);
void Dest(pthread_t *ptid, pthread_t *ctid);

int main(int argc, char **argv)
{
    
    pthread_t ptid[6];// Define producer threads 
    pthread_t ctid[6];// Define consumer threads 
    Init(&ptid[0], &ctid[0]);// initialization 
    Dest(&ptid[0], &ctid[0]);// Uninitialize 
    
    return 0;
}

void *producer(void *arg)
{
    // producer 
    while(1){
    // Always produce 
        pthread_mutex_lock(&mutex);
        struct Node *pnew = (struct Node*)malloc(sizeof(struct Node));// Create a new node 
        pnew -> number = rand() % 100;// Initialize node 
        pnew -> next = head;// The head of the list is inserted 
        head = pnew;// The head node moves forward 
        printf("Producer: number = %d, tid = %ld\n", pnew -> number, pthread_self());
        pthread_mutex_unlock(&mutex);

        pthread_cond_broadcast(&cond);// After production, inform all blocked consumers to consume 

        sleep(rand() % 3);// Take a nap , Avoid producing too fast 
    }
    return NULL;
}

void *consumer(void *arg)
{
    
    while(1){
    // Keep spending 
        pthread_mutex_lock(&mutex);
        while(head == NULL){
    // Using conditional variables 
            pthread_cond_wait(&cond, &mutex);
        }
        struct Node *pnode = head;// Take out the head node 
        printf("Consumer: number = %d, tid = %ld\n", pnode -> number, pthread_self());
        head = pnode -> next;// Offset the head node , Create a new head node 
        free(pnode);// Delete the original leading node 
        pthread_mutex_unlock(&mutex);

        sleep(rand() % 3);// Empathy 
    }
    return NULL;
}

void Init(pthread_t *ptid, pthread_t *ctid)
{
    
    // Initialize mutex and condition variables 
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    // Initialization thread 
    for(int i = 0; i < 6; i++){
    
        pthread_create(&ptid[i], NULL, producer, NULL);
    }
    for(int i = 0; i < 6; i++){
    
        pthread_create(&ctid[i], NULL, consumer, NULL);
    }
}

void Dest(pthread_t *ptid, pthread_t *ctid)
{
    
    // De initializing mutex and condition variables 
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    // Uninitialize the thread 
    for (int i = 0; i < 6; i++){
    
        pthread_join(ptid[i], NULL);
    }
    for(int i = 0; i < 6; i++){
    
        pthread_join(ctid[i], NULL);
    }
}
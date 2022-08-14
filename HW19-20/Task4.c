#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<string.h>
#include<signal.h>
#include<fcntl.h>
#include<sys/stat.h>


sem_t emptySem, fullSem;
pthread_mutex_t mux;
int COUNT = 10;
int top = 0;

typedef struct Storage{
    int barcode;
    enum definiton{Kola =1,Fanta =2,Sprite =3 ,Voda =4,Pepsi =5} name;
    double price;
    struct Storage  *next;
}Storage;

Storage *buff = NULL;

void init_random_product(Storage *st){
    
    st->barcode = 1000000 + rand()%999999;
    st->name = (rand()%Pepsi);
    st->price = (rand()%10000)/100.; 
}
void print_product(Storage *st){
    Storage *curStorage = st;
    printf(" Barcode: %d, Definition: %d, Price: %.2lf\n",
                                            curStorage->barcode,curStorage->name,curStorage->price);
}


void *consumer(void *arg){
    
    while(1){
        
    sem_wait(&fullSem);
    
    
    pthread_mutex_lock(&mux);
    Storage *del_prod = buff;
    printf("Pokupka TID: %ld ",pthread_self());
    print_product(buff);
    buff = del_prod->next;
    fprintf(arg,"Barcode: %d, Definition: %d, Price: %.2lf\n",buff->barcode,buff->name,buff->price);
    free(del_prod);

    pthread_mutex_unlock(&mux);
    sleep(1);
    sem_post(&emptySem);}

}

void *producer(void *arg){
    
    while(1){
        
    sem_wait(&emptySem); 
    
    

    pthread_mutex_lock(&mux);
    
    Storage *new_prod = malloc(sizeof(Storage));
    
    init_random_product(new_prod);
    new_prod->next = buff;
    buff = new_prod;
    fprintf(arg,"Barcode: %d, Definition: %d, Price: %.2lf\n",new_prod->barcode,new_prod->name,new_prod->price);

    printf("Dostavka TID: %ld", pthread_self());
    
    print_product(new_prod);
    
    pthread_mutex_unlock(&mux);
    sleep(1);
    sem_post(&fullSem);
    }
}

void signal_handler(int signum){
   exit(0);
}
    

int main(int argc, char **argv){
    srand(time(NULL));
    pthread_mutex_init(&mux,NULL);
    
    int prod =5,cons =6;
    int opt;
    char filename[FILENAME_MAX];
   
       

    while((opt = getopt(argc, argv, ":P:C:M:F:")) != -1) 
    { 
        switch(opt) 
        { 
            case 'P': 
                sscanf(optarg,"%d",&prod); 
                break; 
            case 'C': 
                sscanf(optarg,"%d",&cons); 
                break; 
            case 'M': 
                sscanf(optarg,"%d",&COUNT);
                break; 
            case 'F': 
                strcpy(filename,optarg);
                break;     
            case '?': 
                printf("unknown option: %c\n", optopt);
                break; 
        } 
    } 
    
    if(COUNT > 10){
        fprintf(stderr,"Nadminali ste limita!\n");
        exit(EXIT_FAILURE);
    }
    sem_init(&emptySem,0,COUNT);
    sem_init(&fullSem,0,0);
    int total = prod + cons;

    pthread_t th[total];
    FILE *f= fopen(filename,"r+");
    
    /*struct sigaction sa;
    sa.sa_handler = save_file;
    sa.sa_flags = SA_RESTART;*/ 
    signal(SIGINT,signal_handler);

    for (int i = 0; i < total; i++)
    {
        
        if(i < prod){
            //producer
            if(pthread_create(th+i,NULL,producer,f)){
                perror("creat");
                return -1;
            }

        }
        else{
            if(pthread_create(th+i,NULL,consumer,f)){
                perror("creat");
                return -1;
            }
        }
        
    }


    for (int i = 0; i < total; i++)
    {
        if(pthread_join(th[i],NULL)){
            perror("join");
            exit(-1);
        }
    }


    pthread_mutex_destroy(&mux);
    sem_destroy(&emptySem);
    sem_destroy(&fullSem);
    fclose(f);
   
    
    return 0;    
}
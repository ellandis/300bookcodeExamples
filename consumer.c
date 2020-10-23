#include<stdio.h>
#include<stdlib.h>
#define True 1
#define False 0
#define BUFFER_SIZE 6
int buffer[] =  {1,2,3,4,5,6};

// does not work yet


void consumer(int,int);
void producer(int,int);


int main(int argc, char const *argv[])
{
    int count;
    while(1){
        printf("What is the count\n");
        scanf("%d", &count);
        producer(count,count+1);
    }
    //consumer(3,3);
    producer(1,3);
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("buffer[%d] = %d\n",i,buffer[i]);
    }
    
    
    return 0;
}

void consumer(int count,int next_consumed){
    int out = 0;
    while (True)
    {
        while(count == 0){
           ;//do nothing
        }
        next_consumed = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("%d = consumer count\n", count);
        count--;
        if(count == 0){
            break;
        } 
    }
}

void producer(int count, int next_produced){
    int in = 0;
    while (True)
    {
        while (count == BUFFER_SIZE){
            ; //do nothing 
        }
        buffer[in] = next_produced;
        in = (in + 1) % BUFFER_SIZE;
        printf("%d = producer count\n", count);
        count++;  
        if(count == BUFFER_SIZE){
            break;
        }   
    }
    
}


//consumer
// while (true) {
// while (count == 0)
// ; /* do nothing */
// next consumed = buffer[out];
// out = (out + 1) % BUFFER SIZE;
// count--;
// }

// producer
// while (true) {
// /* produce an item in next produced */
// while (count == BUFFER SIZE)
// ; /* do nothing */
// }
// buffer[in] = next produced;
// in = (in + 1) % BUFFER SIZE;
// count++;
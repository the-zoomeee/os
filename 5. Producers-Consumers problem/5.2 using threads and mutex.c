#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define BUFFER_SIZE 5


int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int count = 0;              // Track items in the buffer
pthread_mutex_t mutex;      // Mutex for buffer access
pthread_cond_t not_empty;   // Condition variable for non-empty buffer
pthread_cond_t not_full;    // Condition variable for non-full buffer


void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100;  // Produce an item
        pthread_mutex_lock(&mutex);


        while (count == BUFFER_SIZE) {
            pthread_cond_wait(&not_full, &mutex);  // Wait if buffer is full
        }


        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        count++;


        pthread_cond_signal(&not_empty);  // Signal that buffer is not empty
        pthread_mutex_unlock(&mutex);


        sleep(1);  // Simulate time taken to produce
    }
}


void *consumer(void *arg) {
    int item;
    while (1) {
        pthread_mutex_lock(&mutex);


        while (count == 0) {
            pthread_cond_wait(&not_empty, &mutex);  // Wait if buffer is empty
        }


        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        count--;


        pthread_cond_signal(&not_full);  // Signal that buffer is not full
        pthread_mutex_unlock(&mutex);


        sleep(1);  // Simulate time taken to consume
    }
}


int main() {
    pthread_t prod, cons;


    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);


    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);


    pthread_join(prod, NULL);
    pthread_join(cons, NULL);


    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);


    return 0;
}

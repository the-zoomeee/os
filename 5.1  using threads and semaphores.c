#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


#define BUFFER_SIZE 5


int buffer[BUFFER_SIZE];
int in = 0, out = 0;
sem_t empty;     // Semaphore to count empty slots
sem_t full;      // Semaphore to count filled slots
sem_t mutex;     // Semaphore to ensure mutual exclusion


void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100;  // Produce an item
        sem_wait(&empty);     // Wait for an empty slot
        sem_wait(&mutex);     // Lock buffer access


        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;


        sem_post(&mutex);     // Unlock buffer access
        sem_post(&full);      // Increment the full slot count


        sleep(1);             // Simulate time taken to produce
    }
}


void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full);      // Wait for a filled slot
        sem_wait(&mutex);     // Lock buffer access


        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;


        sem_post(&mutex);     // Unlock buffer access
        sem_post(&empty);     // Increment the empty slot count


        sleep(1);             // Simulate time taken to consume
    }
}


int main() {
    pthread_t prod, cons;


    sem_init(&empty, 0, BUFFER_SIZE);  // Initialize empty to BUFFER_SIZE
    sem_init(&full, 0, 0);             // Initialize full to 0
    sem_init(&mutex, 0, 1);            // Initialize mutex to 1


    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);


    pthread_join(prod, NULL);
    pthread_join(cons, NULL);


    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);


    return 0;
}

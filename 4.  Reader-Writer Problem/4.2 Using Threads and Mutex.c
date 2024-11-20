#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t rw_mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for writers
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;    // Mutex for reader count
int read_count = 0; // Number of readers
int data = 0; // Shared resource

void *reader(void *arg) {
    int id = *(int *)arg;

    pthread_mutex_lock(&mutex);
    read_count++;
    if (read_count == 1) {
        pthread_mutex_lock(&rw_mutex); // First reader locks writer
    }
    pthread_mutex_unlock(&mutex);

    // Reading the shared resource
    printf("Reader %d: read data = %d\n", id, data);

    pthread_mutex_lock(&mutex);
    read_count--;
    if (read_count == 0) {
        pthread_mutex_unlock(&rw_mutex); // Last reader unlocks writer
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int id = *(int *)arg;

    pthread_mutex_lock(&rw_mutex);

    // Writing to the shared resource
    data++;
    printf("Writer %d: wrote data = %d\n", id, data);

    pthread_mutex_unlock(&rw_mutex);

    return NULL;
}

int main() {
    pthread_t readers[5], writers[3];
    int reader_ids[5] = {1, 2, 3, 4, 5};
    int writer_ids[3] = {1, 2, 3};

    for (int i = 0; i < 5; i++) {
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(writers[i], NULL);
    }

    pthread_mutex_destroy(&rw_mutex);
    pthread_mutex_destroy(&mutex);

    return 0;
}

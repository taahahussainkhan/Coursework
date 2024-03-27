#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

pthread_mutex_t mutex;
sem_t full, empty;

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void *producer(void *ptr) {
    for (unsigned int i = 1; i <= 10; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        // Produce item and add to the buffer
        buffer[in] = i;
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    pthread_exit(0);
}

void *consumer(void *ptr) {
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    for (unsigned int i = 1; i <= 10; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        // Consume item from the buffer
        printf("%d\n", buffer[out]);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    pthread_exit(0);
}

int main() {
    pthread_t pid1, pid2;

    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    pthread_create(&pid2, NULL, &consumer, NULL);
    pthread_create(&pid1, NULL, &producer, NULL);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}

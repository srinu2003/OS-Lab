#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
#define TRUE 1
#define FALSE 0

int buffer[N];
int in = 0, out = 0;
sem_t mutex, full, empty;

void *producer(void *arg) {
    int produced = 0;
    while (TRUE) {
        produced++;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = produced;
        printf("Produced item: %d\n", buffer[in]);
        in = (in + 1) % N;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void *consumer(void *arg) {
    int consumed;
    while (TRUE) {
        sem_wait(&full);
        sem_wait(&mutex);
        consumed = buffer[out];
        printf("Consumed item: %d\n", consumed);
        out = (out + 1) % N;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
    }
}

int main() {
    pthread_t prod, cons;
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, N);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    return 0;
}
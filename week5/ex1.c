//
// Created by roman on 15.09.2020.
//
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 10
pthread_t thread_id[NUM_THREADS];
void * messageThreat(int i) {
    printf("Hello from thread %d - I was created in iteration %d !",  (int) pthread_self(), i);
    pthread_exit(NULL);


}
int main() {
    int check;

    for (int i = 0; i < NUM_THREADS; i++) {
        check = pthread_create(&thread_id[i], NULL, messageThreat, i);
        if (check) {
            printf("\nERROR: return code from pthread_create is %d \n", check);
            exit(1);
        }
        printf("\nCreated new thread (%d) in iteration %d ...\n", (int) thread_id[i], i);
        pthread_join(thread_id[i], NULL);
        printf("\nExit from thread (%d) from iteration %d ...\n", (int) thread_id[i], i);

    }
    pthread_exit(NULL);
}


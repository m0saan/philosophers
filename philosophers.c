//
// Created by Mohammad  Boustta on 5/30/21.
//

#include "philosophers.h"

#define BIG 1000000
uint32_t counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count_to_big(void *arg){
    for (int i = 0; i < BIG; ++i) {
        pthread_mutex_lock(&lock);
        ++counter;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(int ac, char **av) {
    pthread_t pthread;
    pthread_create(&pthread, NULL, count_to_big, NULL);
    // count_to_big(NULL);
    count_to_big(NULL);
    pthread_join(pthread, NULL);
    printf("the value of counter is: %d\n", counter);
    return EXIT_SUCCESS;
}

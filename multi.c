#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <time.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    fib(37);
    fib(37);
    fib(37);
    fib(37);
    fib(37);
    fib(37);
    fib(37);
    fib(37);
    fib(37);
    fib(37);
    return NULL;
}

int main()
{
    clock_t start = clock(), diff;

    pthread_t thread_id_01;
    pthread_t thread_id_02;
    pthread_t thread_id_03;
    pthread_t thread_id_04;

    pthread_create(&thread_id_01, NULL, myThreadFun, NULL);
    pthread_create(&thread_id_02, NULL, myThreadFun, NULL);
    pthread_create(&thread_id_03, NULL, myThreadFun, NULL);
    pthread_create(&thread_id_04, NULL, myThreadFun, NULL);

    pthread_join(thread_id_01, NULL);
    pthread_join(thread_id_02, NULL);
    pthread_join(thread_id_03, NULL);
    pthread_join(thread_id_04, NULL);

    diff = clock() - start;

    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Time taken %d seconds %d milliseconds\n", msec / 1000, msec % 1000);

    exit(0);
}

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
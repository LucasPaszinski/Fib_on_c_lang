#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <time.h>

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    for (size_t i = 0; i < 100; i++)
    {
        fib(37);
    }

    return NULL;
}


void single()
{
    clock_t start = clock(), diff;

    for (size_t i = 0; i < 400; i++)
    {
        fib(37);
    }

    diff = clock() - start;

    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Time taken to 400 fib of 37 on single thread %d seconds %d milliseconds\n", msec / 1000, msec % 1000);
}

void multi_thread()
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
    printf("Time taken to 400 fib of 37 in four threads %d seconds %d milliseconds\n", msec / 1000, msec % 1000);
}

int main()
{
    //single();
    multi_thread();
    exit(0);
}


//// OLHAR CÒDIGO NOVO NO REPLTIT

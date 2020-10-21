#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define MAX 10000

int sum = 0;

void *p1(void *arg)
{
    int i;
    for(int i = 0; i<MAX; i++) 
        sum += 1;
}

void *p2(void *arg) 
{
    int i;
    for(i=0; i<MAX; i++)
        sum -= 1;
}

int main()
{
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, p1, NULL);
    pthread_create(&tid2, NULL, p2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("%d\n", sum);
}
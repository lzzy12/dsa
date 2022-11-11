#include "stdio.h"
#include "stdlib.h"
#include <stdlib.h>

typedef struct queue{
    int *arr;
    int head;
    int tail;
    int size;
    int maxSize;
} queue;

void qInit(queue *q, int max){
    q->arr = malloc(sizeof(int) * max);
    q->head = q->tail = -1;
    q->size = 0;
    q->maxSize = max;
}

void qPush(queue *q, int val){
    if (q->size == q->maxSize){
        printf("queue full\n");
        return;
    }
    if (q->tail == -1){
        q->head = 0;
    }
    q->arr[++q->tail] = val;
    q->size++;
}

int qPop(queue *q, int *k){
    if (q->size == 0){
        printf("Queue empty\n");
        return -1;
    }
    *k = q->arr[q->head];
    int i = 1;
    while (i <= q->tail) {
        q->arr[i - 1] = q->arr[i];
        i++;
    }
    q->size--;
    return 0;
}
int main(){
    queue q;
    qInit(&q, 5);
    qPush(&q, 5);
    qPush(&q, 6);
    qPush(&q, 3);
    qPush(&q, 7);
    qPush(&q, 1);
    qPush(&q, 2);
    int k;
    qPop(&q, &k);
    printf("%d\n", k);
    qPop(&q, &k);
    printf("%d\n", k);
    qPop(&q, &k);
    printf("%d\n", k);
    qPop(&q, &k);
    printf("%d\n", k);
    qPop(&q, &k);
    printf("%d\n", k);
    qPop(&q, &k);
    printf("%d\n", k);
    qPop(&q, &k);
    printf("%d\n", k);
    return 0;
}
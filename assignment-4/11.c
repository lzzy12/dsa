#include "stdio.h"

#define arr_size 4
#define arr_nums 3
typedef struct queue {
    int arr[arr_size][arr_nums]; // 3 arrays of array with size 4
    int index;
    int R;
} queue;

void initQ(queue *q){
    q->R = -1;
    q->index = 0;
}

void qPush(queue *q, int val){
    if (q->R + 1 == arr_size * arr_nums){
        printf("Queue is full;\n");
        return;
    }
    for (int i = 0 ;  i <= q->R; i++){
        q->arr[q->index][i % arr_size] = val;
        
    } 
}
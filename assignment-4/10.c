

#include <stdio.h>
#include <stdlib.h>
typedef struct queue{
    int *evenArr;
    int *oddArr;
    int evenFront;
    int oddFront;
    int evenRear;
    int oddRear;
    int evenMax;
    int oddMax;
} queue;
void initQ(queue *q, int evenSz, int oddSz){
    q->evenArr = calloc(evenSz, sizeof(int));
    q->oddArr = calloc(oddSz, sizeof(int));
    q->evenFront = q->oddFront = q->evenRear = q->oddRear = -1;
    q->evenMax = evenSz;
    q->oddMax = oddSz;
}
int push(queue *q, int val){
    if (q->evenRear + 1 == q->evenMax && q->oddRear + 1== q->oddMax){
        printf("Queue full");
        return -1;
    }
    
    if (val % 2 == 0){
        if (q->evenRear + 1 == q->evenMax){
            if (q->oddFront == -1){
                q->oddFront = 0;
            }
            // Even array is full insert into odd (odd array must be partially filled)
            q->oddArr[++q->oddRear] = val;
        }   else{
            if (q->evenFront == -1){
                q->evenFront = 0;
            }
            q->evenArr[++q->evenRear] = val;
        }
    } else{
         if (q->oddRear + 1 == q->oddMax){
            if (q->evenFront == -1){
                q->evenFront = 0;
            }
            // odd array is full insert into even (even array must be partially filled)
            q->evenArr[++q->evenRear] = val;
        }   else{
            if (q->oddFront == -1){
                q->oddFront = 0;
            }
            q->oddArr[++q->oddRear] = val;
        }
    }
    printf("Inserted into key: %d\n", val);
    return 0;
}

int pop(queue *q, int *k){
    if (q->evenRear == q->oddRear && q->oddRear == -1){
        printf("Empty queue\n");
        return -1;
    }
    if (q->evenRear > q->oddRear){
        *k = q->evenArr[q->evenFront];
        int i = 0;
        while (i < q->evenRear) {
            q->evenArr[i] = q->evenArr[i + 1];
            i++;
        }
        q->evenRear--;
    }
    else if (q->oddRear > q->evenRear){
        *k = q->oddArr[q->evenFront];
        int i = 0;
        while (i < q->oddRear) {
            q->oddArr[i] = q->oddArr[i + 1];
            i++;
        }
        q->oddRear--;
    }
    else{
        printf("Equal length: deleting from even\n");
        *k = q->evenArr[q->evenFront];
        int i = 0;
        while (i < q->evenRear) {
            q->evenArr[i] = q->evenArr[i + 1];
            i++;
        }
        q->evenRear--;
    }
    if (q->evenRear == -1){
        q->evenFront = -1;
    }
    if (q->oddRear == -1){
        q->oddFront = -1;
    }
    printf("Deleted element from queue: %d\n", *k);
    return 0;
}
int main(){
    queue q;
    initQ(&q, 4, 5);
    int arr[] = {2, 4, 6, 8, 10, 3, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++){
        push(&q, arr[i]);
    }
    printf("sizeof evenarr: %d, sizeof oddarr: %d\n", q.evenRear, q.oddRear);
    int k;
    pop(&q, &k);
    pop(&q, &k);
    pop(&q, &k);
    pop(&q, &k);
    pop(&q, &k);
    pop(&q, &k);
    pop(&q, &k);
    pop(&q, &k);
    pop(&q, &k);
    pop(&q, &k);
}
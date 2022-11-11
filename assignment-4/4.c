#include "stdio.h"
#include "stdlib.h"

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;


typedef struct queue{
    ListNode *head;
    ListNode *tail;
} queue;

void qInit(queue *q){
    q->head = q->tail = NULL;
}
void qPush(queue *q, int val){
    ListNode *node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    if (!q->tail){
        q->head = q->tail = node;
        return;
    }
    q->tail->next = node;
    q->tail = q->tail->next;
}
int qPop(queue *q, int *k){
    if (!q->head){
        printf("Empty queue\n");
        return -1;
    }
    if (q->head == q->tail){
        *k = q->head->val;
        free(q->head);
        q->head = q->tail = NULL;
        return 0;
    }
    *k = q->head->val;
    ListNode *temp = q->head;
    q->head = q->head->next;
    free(temp);
    return 0;
}

int main(){
    queue q;
    qInit(&q);
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
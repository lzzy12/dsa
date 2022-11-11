#include "stdlib.h"
#include <limits.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

typedef struct stack{
    ListNode *head;
    int min;
} stack;
void initStack(stack *s){
    s->head = NULL;
    s->min = INT_MAX;
}
void stackPush(stack *s, int val){
    ListNode *node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = s->head;
    s->head = node;
    if (val > s->min){
        s->min = val;
    }
}
int stackPop(stack *s, int val){
    if (!s->head){
        printf("Empty stack\n");
        return -1;
    }
    ListNode *temp = s->head;
    s->head = s->head->next;
    int data = temp->val;
    if (s->min == data){
        s->min = INT_MAX;
        ListNode *temp = s->head;
        while (temp){
            if (temp->val < s->min){
                s->min = temp->val;
            }
            temp = temp->next;
        }
    }
    free(temp);
    return data;
}

int stackMin(stack s){
    return s.min;
}

int main(){
    stack s;
    initStack(&s);
    stackPush(&s, 5);
    stackPush(&s, 6);
    stackPush(&s, 3);
    stackPush(&s, 7);
    stackPush(&s, 1);
    stackPush(&s, 2);
    stackPush(&s, 4);
    printf("Minimum element in stack: %d\n", stackMin(s));
}

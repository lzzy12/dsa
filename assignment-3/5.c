#include "COMMON.h"

void printNthNodeFromLast(SingleLL *head, int n){
    int size = 0;
    SingleLL *ptr = head;
    while (ptr) {
        size++;
        ptr = ptr->next;
    }
    if (size < n){
        printf("Nth value from last does not exist\n");
        return;
    }
    ptr = head;
    for (int i = 0; i < size - n; i++){
        ptr = ptr->next;
    }
    printf("%dth node from last is: %d\n", n, ptr->data);
}
int main(){
    initApi();
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    SingleLL *head;
    createLL(&head, 10);
    displayLL(head);
    printNthNodeFromLast(head, n);
}   
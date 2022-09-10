#include "common.h"

void revDoubleLinkedList(DoubleLL **head){
    if (*head == NULL)
        return;
    DoubleLL *ptr = *head;
    DoubleLL *prev = NULL;
    while (ptr) {                                       
        DoubleLL *next = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = next;
        prev = ptr;
        ptr = next;
    }
    prev->prev = NULL;
    (*head) = prev;
}
int main(){
    initApi();
    DoubleLL *head;
    createDoubleLL(&head, 5);
    printf("Begore Reversing: ");
    displayDoubleLL(head);
    revDoubleLinkedList(&head);
    printf("After reverse: ");
    displayDoubleLL(head);
}
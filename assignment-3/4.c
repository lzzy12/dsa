#include "common.h"

void swap2ConsecutiveNodes(SingleLL **head){
    SingleLL *ptr = *head;
    if ((*head)->next){
        ptr = (*head)->next;
        (*head)->next = ptr->next;
        ptr->next = *head;
        (*head) = ptr;
    }
    ptr = (*head)->next->next; 
    SingleLL *prev = (*head)->next;
    while (ptr && ptr->next) {
        SingleLL *next = ptr->next;
        ptr->next = next->next;
        next->next = ptr; 
        prev->next = next;
        prev = ptr;
        ptr = ptr->next;
    }
}
int main(){
    SingleLL *head;
    createLL(&head, 6);
    printf("Before swapping: ");
    displayLL(head);
    printf("after swapping: ");
    swap2ConsecutiveNodes(&head);
    displayLL(head);
}
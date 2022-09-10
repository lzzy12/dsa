#include <stdio.h>
#include "common.h"

void displayReverseLL(SingleLL *head){
    SingleLL *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    while (ptr != head) {
        SingleLL *it = head;
        while (it->next != ptr) {
            it = it->next;
        }
        printf("%d, ", ptr->data);
        ptr = it;
    }
    printf("%d", ptr->data);
    printf("\n");
}

int main(){
    initApi();
    SingleLL *head;
    createLL(&head, 5);
    printf("Forward order: ");
    displayLL(head);
    printf("\nReverse Order: ");
    displayReverseLL(head);
}
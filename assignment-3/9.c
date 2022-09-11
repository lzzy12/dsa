#include "COMMON.h"
#include <stdio.h>

SingleLL* rotateRight(SingleLL* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        SingleLL *ptr = head;
        int size = 0;
        while(ptr){
            size++;
            ptr = ptr->next;
        }
        k = k % size;
        while(k--){
            SingleLL *prev = NULL, *ptr = head;
            while(ptr->next){
                prev = ptr;
                ptr = ptr->next;
            }
            ptr->next = head;
            prev->next = NULL;
            head = ptr;
        }
        return head;
    }
int main(){
    SingleLL *head;
    createLL(&head, 10);
    printf("Before rotation: ");
    displayLL(head);
    head = rotateRight(head, 7);
    printf("After rotation: ");
    displayLL(head);
}
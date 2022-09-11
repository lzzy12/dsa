#include "COMMON.h"
#include <stdio.h>

SingleLL* rotateRight(SingleLL* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        SingleLL *tail = head;
        int size = 1;
        while(tail->next){
            size++;
            tail = tail->next;
        }
        k = k % size;
        SingleLL *ptr = head;
        for (int i = 1; i < size - k; i++){
            ptr = ptr->next;
        }
        tail->next = head;
        head = ptr->next;
        ptr->next = NULL;
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
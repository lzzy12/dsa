#include "COMMON.h"

void deleteAllNodes(SingleLL **head){
    SingleLL *ptr = *head;
    while (*head) {
        *head = ptr->next;
        free(ptr);
        ptr = *head;
    }
}
int getSizeLL(SingleLL *head){
    int c = 0;
    while (head) {
        head = head->next;
        c++;
    }
    return c;
}
int main(){
    SingleLL *head;
    createLL(&head, 10);
    printf("initial size of LL: %d\n", getSizeLL(head));
    deleteAllNodes(&head);
    printf("After deleting all nodes, size of LL: %d\n", getSizeLL(head));
}
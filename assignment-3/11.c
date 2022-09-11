#include "COMMON.h"

SingleLL* reverseList(SingleLL *head){
    SingleLL *ptr = head, *prev = NULL;
    while (ptr) {
        SingleLL *next = head;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    return prev;
}
void solve(SingleLL *head){
    SingleLL *mid = head, *fast = head;
    while (fast) {
        mid = mid->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
    }
    mid = reverseList(mid); // reversed mid
    fast = head;
    while (mid && fast) {
            SingleLL *next = fast->next;
            fast->next = mid;
            mid = mid->next;
            fast = fast->next;
            fast->next = next;
            fast = fast->next;
        }
        fast->next = NULL;
}
int main(){
    SingleLL *head;
    createLL(&head, 10);
    printf("Before reorder: ");
    displayLL(head);
    solve(head);
    printf("After reorder: ");
    displayLL(head);
}
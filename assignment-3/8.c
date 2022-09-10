#include "COMMON.h"
SingleLL* createSingleLLFromArray1(int arr[], int n){
    SingleLL *head;
    createLL(&head, n);
    SingleLL *ptr = head;
    for (int i = 0; i < n; i++){
        ptr->data = arr[i];
        ptr = ptr->next;
    }
    return head;
}
void unique(SingleLL *head){
    if (!head || !head->next)
        return;
    SingleLL *slow = head;
    SingleLL *fast = head->next;
    while (fast) {
        if (slow->data == fast->data){
            slow->next = fast->next;
            free(fast);
            fast = slow->next;
            continue;
        } 
        slow = fast;
        fast = fast->next;
    }
}
int main(){
    int arr[] = {1, 1, 7, 8, 10, 10, 13, 14, 15, 15, 15, 15, 17,17,17};
    const int size = sizeof(arr)/sizeof(int);
    printf("size of array: %d\n", size);
    SingleLL *head = createSingleLLFromArray1(arr, size);
    printf("Before calling unique: ");
    displayLL(head);
    printf("After calling unique: ");
    unique(head);
    displayLL(head);
}
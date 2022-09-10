#include "COMMON.h"

SingleLL* reverseLLUpto(SingleLL *head, int left, int right) {
    if (head == NULL)
            return head;
        if (right <= left)
            return head;
        int i = 1;
        SingleLL *ptr = head;
        while(i < left - 1){
            ptr = ptr->next;
            i++;
        }
        SingleLL *startPrevNode = ptr, *prev;
        ptr = left == 1? ptr: ptr->next;
        SingleLL *startNode = ptr;
        if (!ptr) return head;
        prev = ptr;
        ptr = ptr->next;
        right -= left == 1? 0: 1;
        while(i < right && ptr){
            SingleLL *next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
            i++;
        }
        startPrevNode->next = prev;
        startNode->next = ptr;
        if (left == 1){
            head = prev;
        }
        return head;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int size = sizeof(arr) / sizeof(arr[0]);
    SingleLL *head = createSingleLLFromArray(arr, size), *ptr;
    int m, n;
    printf("Enter value of m and n: ");
    scanf("%d %d", &m, &n);
    printf("Without reverse: ");
    displayLL(head);
    printf("After reverse: ");
    head = reverseLLUpto(head, m, n);
    displayLL(head);
}
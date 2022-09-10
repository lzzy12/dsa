#include "COMMON.h"
#include <stdio.h>
#include <stdlib.h>

void arrangeOddEven(SingleLL **head){
    if (*head == NULL)
        return;
    SingleLL *odd, *even, *oddPtr, *evenPtr, *ptr = *head;
    odd = getNewNode(0); // add dummy node
    even = getNewNode(0); // dummy node
    oddPtr = odd;
    evenPtr = even;
    while (ptr) {
        SingleLL *next = ptr->next;
        if (ptr->data % 2 == 1){
            oddPtr->next = ptr;
            oddPtr = oddPtr->next;
        } else{
            evenPtr->next = ptr;
            evenPtr = evenPtr->next;
        }
        ptr = next;
    }
    ptr = odd;
    odd = odd->next;
    free(ptr);
    ptr = even;
    even = even->next;
    free(ptr);
    if (odd == NULL){
        *head = even;
        return;
    }
    oddPtr->next = even;
    evenPtr->next = NULL;
    *head = odd;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13};
    const int size = sizeof(arr)/sizeof(int);
    SingleLL *head = createSingleLLFromArray(arr, size);
    printf("Initial List: \n");
    displayLL(head);
    arrangeOddEven(&head);
    printf("After modification:\n");
    displayLL(head);
}
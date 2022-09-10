#include "COMMON.h"
#include <stdio.h>

DoubleLL* join(DoubleLL *h1, DoubleLL *h2){

    if (!h1)
        return h2;
    if (!h2)
        return h1;

    DoubleLL *head = h1, *ptr;
    DoubleLL *h1Ptr = h1->next, *h2Ptr = h2->next;
    head->next = h2;
    head->next->prev = head;
    ptr = head->next;
    int i = 0;

    do {
        if (i == 100)
            break;
        DoubleLL *next;
        if (i % 2 == 0)
        {
            next = h1Ptr->next;
            h1Ptr->prev = ptr;
            ptr->next = h1Ptr;
            h1Ptr = next;
        } else{
            next = h2Ptr->next;
            h2Ptr->prev = ptr;
            ptr->next = h2Ptr;
            h2Ptr = next;
        }
        i++;
        ptr = ptr->next;
    } while(h1Ptr != h1 && h2Ptr != h2);
    if (h1Ptr != h1){
        while(h1Ptr != h1){
            h1Ptr->prev = ptr;
            ptr->next = h1Ptr;
            h1Ptr = h1Ptr->next;
            ptr = ptr->next;
        }
    }
    if (h2Ptr != h2){
        while(h2Ptr != h2){
            h2Ptr->prev = ptr;
            ptr->next = h2Ptr;
            h2Ptr = h2Ptr->next;
            ptr = ptr->next;
        }
    }
    ptr->next = head;
    head->prev = ptr;
    return head;
}
int main(){
    DoubleLL *h1, *h2;
    initApi();
    createDoublyCircularList(&h1, 5);
    createDoublyCircularList(&h2, 5);
    printf("First list: \n");
    displayDoubleCircularList(h1);
    printf("Second List: \n");
    displayDoubleCircularList(h2);
    DoubleLL *newList = join(h1, h2);
    printf("Joined List: \n");
    displayDoubleCircularList(newList);
}
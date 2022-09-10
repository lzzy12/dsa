#include "COMMON.h"

void reverseLL(SingleLL **head) {
  if (*head == NULL)
    return;
  SingleLL *ptr = *head, *prev = NULL, *t;

  while (ptr) {
    t = ptr->next;
    ptr->next = prev;
    prev = ptr;
    ptr = t;
  }
  *head = prev;
  return;
}
int isPalindrome(SingleLL *head) {
  SingleLL *mid = head, *ptr = head;
  while (ptr) {
    ptr = ptr->next;
    if (ptr) {
      ptr = ptr->next;
    }
    mid = mid->next;
  }
  reverseLL(&mid);
  ptr = head;
  while (mid != NULL) {
    if (mid->data != ptr->data)
      return 0;
    mid = mid->next;
    ptr = ptr->next;
  }
  return 1;
}
void deleteAllNodes(SingleLL **head){
    SingleLL *ptr = *head;
    while (*head) {
        *head = ptr->next;
        free(ptr);
        ptr = *head;
    }
}
void takeInput(SingleLL *head, int size){
    SingleLL *ptr = head;
    ptr = head;
    while (size > 0) {
        printf("Enter value for node: ");
        scanf("%d", &ptr->data);
        ptr = ptr->next;
        size--;
    }
}
int main() {
    SingleLL *head;
    createLL(&head, 5);
    int length = -1;
    while (1) {
        int length;
        printf("Enter size of the list (0 to exit): ");
        scanf("%d", &length);
        if (length == 0)
            break;
        createLL(&head, length);
        takeInput(head, length);
        if (isPalindrome(head)){
            printf("Linked list is palindrome\n");
        } else{
            printf("Not a palindrome\n");
        }
        deleteAllNodes(&head);
    }
}
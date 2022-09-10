#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct SingleLL{
    int data;
    struct SingleLL *next;
} SingleLL;
typedef struct DoubleLL{
    int data;
    struct DoubleLL *next;
    struct DoubleLL *prev;
} DoubleLL;
void initApi(){
    srand((unsigned int)time(NULL));
}
void* getNewNode(int type){
    if (type == 0){
        SingleLL *node  = malloc(sizeof(SingleLL));
        node->data = rand() % 30 + 1;
        node->next = NULL;
        return node;
    } else{
        DoubleLL *node = malloc(sizeof(DoubleLL));
        node->data = rand() % 30 + 1;
        node->next = NULL;
        node->prev = NULL;
        return node;
    }
}
void createLL(SingleLL **head, int n){
    *head = getNewNode(0);
    SingleLL *ptr, *last = *head;
    while(n - 1){
        ptr = getNewNode(0);
        last->next = ptr;
        last = ptr;
        n--;
    }
}

int insertSingle(SingleLL **head, int pos, int data){
    SingleLL *node = getNewNode(0);
    node->data = data;
    if (pos == 0){
        node->next = *head;
        *head = node;
        return 0;
    }
    SingleLL *ptr = *head;
    while(pos - 1 && ptr){
        ptr = ptr->next;
        pos--;
    }
    if (ptr){
        node->next = ptr->next;
        ptr->next = node;
    } else{
        return -1;
    }
    return 0;
}
int deleteSingle(SingleLL **head, int pos){
    if (pos == 0){
        SingleLL *t = *head;
        *head = (*head)->next;
        free(t);
        return 0;
    }
    SingleLL *ptr = *head, *prev = NULL;
    while(pos && ptr){
        prev = ptr;
        ptr = ptr->next;
        pos--;
    }
    if (ptr){
        prev->next = ptr->next;
        free(ptr);
    } else{
        if(pos > 0){
            printf("Position greater than size\n");
        }
        return -1;
    }
    return 0;
}
void createDoubleLL(DoubleLL **head, int n){
    *head = getNewNode(1);
    DoubleLL *ptr, *last = *head;
    n--;
    while(n){
        ptr = getNewNode(1);
        ptr->prev = last;
        last->next = ptr;
        last = ptr;
        n--;
    }
}
int insertDoubleLL(DoubleLL **head, int pos, int data){
    DoubleLL *node = getNewNode(1);
    node->data = data;
    if (pos == 0){
        node->next = *head;
        (*head)->prev = node;
        *head = node;
        return 0;
    }
    DoubleLL *ptr = *head;
    while(pos - 1 && ptr){
        ptr = ptr->next;
        pos--;
    }
    if (ptr){
        node->next = ptr->next;
        node->prev = ptr;
        ptr->next = node;
        if (node->next){
            node->next->prev = node;
        }
    } else{
        return -1;
    }
    return 0;
}
int deleteDoubleLL(DoubleLL **head, int pos){
    if (pos == 0){
        DoubleLL *t = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(t);
        return 0;
    }
    DoubleLL *ptr = *head, *prev = NULL;
    while(pos && ptr){
        prev = ptr;
        ptr = ptr->next;
        pos--;
    }
    if (ptr){
        prev->next = ptr->next;
        if (ptr->next)
            ptr->next->prev = prev;
        free(ptr);
    } else{
        if(pos > 0){
            printf("Position greater than size\n");
        }
        return -1;
    }
    return 0;
}
void displayLL(SingleLL *head){
    if (head == NULL)
        printf("\nNo elements in the list\n");
    while(head != NULL){
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");
}
void displayDoubleLL(DoubleLL *head){
    if (head == NULL)
        printf("\nNo elements in the list\n");
    DoubleLL *ptr = head;
    printf("Forward: ");
    while(ptr->next != NULL){
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n\nReverse: ", ptr->data);
    while (ptr != NULL) {
        printf("%d, ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

void createSingularCircularList(SingleLL **head, int n){
    createLL(head, n);
    SingleLL *ptr = *head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = *head;
}

void insertSingularCircularList(SingleLL **head, int pos, int data){
    SingleLL *node = getNewNode(0);
    node->data = data;
    if (pos < 0)
        return;
    SingleLL *ptr = *head;
    if (pos == 0){
        do {
            ptr = ptr->next;
        } while(ptr->next != *head);
        printf("%d", ptr->data);
        ptr->next = node;
        node->next = *head;
        *head = node;
        return;
    }
    ptr = *head;
    while (pos - 1) {
        ptr = ptr->next;
        pos--;
    }
    node->next = ptr->next;
    ptr->next = node;
}

void deleteSingularCircularList(SingleLL **head, int pos){
    SingleLL *ptr = *head;
    if (pos == 0){
        do {
            ptr = ptr->next;
        } while(ptr->next != *head);
        ptr->next = (*head)->next;
        free(*head);
        *head = ptr->next;
        return;
    }
    SingleLL *prev = NULL;
    while (pos) {
        prev = ptr;
        ptr = ptr->next;
        pos--;
    }
    if (prev)
        prev->next = ptr->next;
    free(ptr);
}
void displaySingularCircularList(SingleLL *head){
    if (head == NULL)
        printf("\nNo elements in the list\n");
    printf("Singular Circular Linked List: ");
    SingleLL *ptr = head;
    do{
        printf("%d ,", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
    printf("\n");
}

void createDoublyCircularList(DoubleLL **head, int n){
    createDoubleLL(head, n);
    DoubleLL *ptr = *head;
    while (ptr->next) {
        ptr = ptr->next;
    }
    ptr->next = *head;
    (*head)->prev = ptr;
}
void displayDoubleCircularList(DoubleLL *head){
    DoubleLL *ptr = head;
    printf("Forward: ");
    do{
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
    printf("\nReverse: ");
    ptr = ptr->prev;
    do {
        printf("%d, ", ptr->data);
        ptr = ptr->prev;
    } while(ptr != head->prev);

    printf("\n");

}

SingleLL* createSingleLLFromArray(int arr[], int n){
    SingleLL *head;
    createLL(&head, n);
    SingleLL *ptr = head;
    for (int i = 0; i < n; i++){
        ptr->data = arr[i];
        ptr = ptr->next;
    }
    return head;
}
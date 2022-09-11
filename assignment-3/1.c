#include "COMMON.h"

int main(){
    initApi();
    int cmd = -1;
    SingleLL *sHead = NULL;
    DoubleLL *dequeue = NULL;
    SingleLL *singularCircular = NULL;
    while(cmd != 0){
        
        printf("Enter command number: \n"
        "\nSingle Linked List:\n\n"
        "1) Create Linked list with random values\n"
        "2) Insert In single Linked List\n"
        "3) Delete In single Linked List\n"
        "4) Display list\n"
        "\nDOUBLE LINKED LIST\n\n"
        "5) Create Doubly linked list with random values\n"
        "6) Insert In Doubly Linked List\n"
        "7) Delete In Doubly Linked List\n"
        "8) Display Double Linked list\n"
        "\nSINGLE CIRCULAR LINKED LIST\n\n"
        "9) Create Singular Circular linked list with random values\n"
        "10) Insert In Singular Circular Linked List\n"
        "11) Delete In Singular Circular Linked List\n"
        "12) Display Singular Circular Linked list\n"
        "\nDOUBLE CIRCULAR LINKED LIST\n\n"
        "13) Create Double Circular linked list with random values\n"
        "14) Insert In Double Circular Linked List\n"
        "15) Delete In Double Circular Linked List\n"
        "16) Display Double Circular Linked list\n");
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                printf("Create random single Linked List");
                {
                    int n;
                    printf("Enter number of nodes: ");
                    scanf("%d", &n);
                    createLL(&sHead, n);
                }
                break;
            case 2:
                {
                    printf("Enter Insert pos: ");
                    int pos, data;
                    scanf("%d", &pos);
                    printf("Enter data: ");
                    scanf("%d", &data);
                    insertSingle(&sHead, pos, data);
                }
                break;
            case 3:
            {
                printf("Enter pos to be deleted: ");
                int n;
                scanf("%d", &n);
                deleteSingle(&sHead, n);
            }
                break;
            case 4:{
                displayLL(sHead);
            }
                break;
            case 5:{
                printf("Create random single Linked List");
                {
                    int n;
                    printf("Enter number of nodes: ");
                    scanf("%d", &n);
                    createDoubleLL(&dequeue, n);
                }
                break;
            }
            case 6: {
                {
                    printf("Enter Insert pos: ");
                    int pos, data;
                    scanf("%d", &pos);
                    printf("Enter data: ");
                    scanf("%d", &data);
                    insertDoubleLL(&dequeue, pos, data);
                    
                }
                break;
            }
            case 7:{
                printf("Enter pos to be deleted: ");
                int n;
                scanf("%d", &n);
                deleteDoubleLL(&dequeue, n);
                break;
            }
            case 8:{
                displayDoubleLL(dequeue);
            }
                break;
            case 9:
                printf("Create random single Linked List");
                {
                    int n;
                    printf("Enter number of nodes: ");
                    scanf("%d", &n);
                    createSingularCircularList(&singularCircular, n);
                }
                break;
            case 10:
                {
                    printf("Enter Insert pos: ");
                    int pos, data;
                    scanf("%d", &pos);
                    printf("Enter data: ");
                    scanf("%d", &data);
                    insertSingularCircularList(&singularCircular, pos, data);
                }
                break;
            case 11:
            {
                printf("Enter pos to be deleted: ");
                int n;
                scanf("%d", &n);
                deleteSingularCircularList(&singularCircular, n);
            }
                break;
            case 12:{
                displaySingularCircularList(singularCircular);
                break;
            }
            case 13:
                printf("Create random single Linked List");
                {
                    int n;
                    printf("Enter number of nodes: ");
                    scanf("%d", &n);
                    createLL(&sHead, n);
                }
                break;
            case 14:
                {
                    printf("Enter Insert pos: ");
                    int pos, data;
                    scanf("%d", &pos);
                    printf("Enter data: ");
                    scanf("%d", &data);
                    insertSingle(&sHead, pos, data);
                }
                break;
            case 15:
            {
                printf("Enter pos to be deleted: ");
                int n;
                scanf("%d", &n);
                deleteSingle(&sHead, n);
            }
                break;
            case 16:{
                displayLL(sHead);
            }
                break;
        }
    }
}
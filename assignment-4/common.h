#include "stdio.h"
#include "stdlib.h"

typedef struct ListNode{
    int val;
    struct ListNode *next;
} ListNode;

typedef struct stack{
    ListNode *head;
} stack;
void initStack(stack *s){
    s->head = NULL;
}
void stackPush(stack *s, int val){
    ListNode *node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = s->head;
    s->head = node;
}
int stackPop(stack *s, int val){
    if (!s->head){
        printf("Empty stack\n");
        return -1;
    }
    ListNode *temp = s->head;
    s->head = s->head->next;
    int data = temp->val;
    free(temp);
    return data;
}

typedef struct queue{
    ListNode *head;
    ListNode *tail;
} queue;

void qInit(queue *q){
    q->head = q->tail = NULL;
}
void qPush(queue *q, int val){
    ListNode *node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    if (!q->tail){
        q->head = q->tail = node;
        return;
    }
    q->tail->next = node;
    q->tail = q->tail->next;
}
int qPop(queue *q, int *k){
    if (!q->head){
        printf("Empty queue\n");
        return -1;
    }
    if (q->head == q->tail){
        *k = q->head->val;
        free(q->head);
        q->head = q->tail = NULL;
        return 0;
    }
    *k = q->head->val;
    ListNode *temp = q->head;
    q->head = q->head->next;
    free(temp);
    return 0;
}


typedef struct TreeNode{
    struct TreeNode *left, *right;
    int val;
} TreeNode;

typedef struct ListNodeTree{
    TreeNode *val;
    struct ListNodeTree *next;
} ListNodeTree;

typedef struct queueTree{
    ListNodeTree *head;
    ListNodeTree *tail;
    int size;
} queueTree;

void queueTreeInit(queueTree *q){
    q->head = q->tail = NULL;
    q->size = 0;
}
void queueTreePush(queueTree *q, TreeNode *val){
    ListNodeTree *node = malloc(sizeof(ListNodeTree));
    node->val = val;
    node->next = NULL;
    q->size++;
    if (!q->tail){
        q->head = q->tail = node;
        return;
    }
    q->tail->next = node;
    q->tail = q->tail->next;
    
}
int qTreePop(queueTree *q, TreeNode **k){
    if (!q->head){
        printf("Empty queue\n");
        return -1;
    }
    q->size--;
    *k = q->head->val;
    if (q->head == q->tail){
        free(q->head);
        q->head = q->tail = NULL;
        return 0;
    }
    ListNodeTree *temp = q->head;
    q->head = q->head->next;
    free(temp);
    return 0;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root){
            root = malloc(sizeof(TreeNode));
            root->val = val;
            root->left = NULL;
            root->right = NULL;
            printf("Inserted %d\n", val);
        } else if (val > root->val){
            root->right = insertIntoBST(root->right, val);
            return root;
        }
        else {
            root->left = insertIntoBST(root->left, val);
            return root;
        }
        return root;
    }

TreeNode* getRandomTree(){
    TreeNode *root = NULL;
    
    for (int i = 0; i < rand() % 50; i++){
        root = insertIntoBST(root, rand() % 30);
    }
    return root;
}
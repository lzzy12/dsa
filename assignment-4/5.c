#include "stdio.h"
#include "stdlib.h"

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
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

void levelOrder(TreeNode *root){
    if (!root){
        printf("NULL tree\n");
        return;
    }
    queueTree q;
    queueTreeInit(&q);
    queueTreePush(&q, root);
    while (q.size > 0) {
        // printf("q.head: %p, size: %d\n", q.head, q.size);
        int sz = q.size;
        while(sz--){
            TreeNode *curr;
            qTreePop(&q, &curr);
            if (curr->left)
                queueTreePush(&q, curr->left);
            if (curr->right)
                queueTreePush(&q, curr->right);
            printf("%d, ", curr->val);
        }
        printf("\n");
    }
}
int main(){

    TreeNode *root = NULL;

    for (int i = 0; i < rand() % 50; i++){
        root = insertIntoBST(root, rand() % 30);
    }
    levelOrder(root);
}

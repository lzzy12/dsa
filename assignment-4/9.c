#include <stdio.h>
#include "time.h"
#include "stdlib.h"

typedef struct TreeNode{
    struct TreeNode *left, *right;
    int val;
} TreeNode;

TreeNode* deleteIterative(TreeNode* root, int key)
{
    TreeNode* curr = root;
    TreeNode* prev = NULL;
    while (curr != NULL && curr->val != key) {
        prev = curr;
        if (key < curr->val)
            curr = curr->left;
        else
            curr = curr->right;
    }
 
    if (curr == NULL) {
        printf("Key not found!\n");
        return root;
    }
 
    if (curr->left == NULL || curr->right == NULL) {
 
        TreeNode* newCurr;
 
        if (curr->left == NULL)
            newCurr = curr->right;
        else
            newCurr = curr->left;
 
        if (prev == NULL)
            return newCurr;
 
        if (curr == prev->left)
            prev->left = newCurr;
        else
            prev->right = newCurr;
 
        free(curr);
    }
 
    else {
        TreeNode* p = NULL;
        TreeNode* temp;
        temp = curr->right;
        while (temp->left != NULL) {
            p = temp;
            temp = temp->left;
        }
 
        if (p != NULL)
            p->left = temp->right;
 
        else
            curr->right = temp->right;
 
        curr->val = temp->val;
        free(temp);
    }
    printf("Deleted %d\n", key);
    return root;
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
int main(){
    srand(time(NULL));
    TreeNode *root = NULL;
    int arr[] = {2, 1, 3};
    root = getRandomTree();
    root = insertIntoBST(root, 6900);
    root = deleteIterative(root, 6900);
}
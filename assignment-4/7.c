#include "stdio.h"
#include "stdlib.h"
typedef struct TreeNode{
    struct TreeNode *left, *right;
    int val;
} TreeNode;

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
TreeNode *invertTree(TreeNode *root){
    if (!root)
        return NULL;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main(){

    TreeNode *root = NULL;

    root = getRandomTree();

    root = invertTree(root);
}
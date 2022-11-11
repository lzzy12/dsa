
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct TreeNode{
    struct TreeNode *left, *right;
    int val;
} TreeNode;

int countNodes(TreeNode* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
 
bool isComplete (struct TreeNode* root, unsigned int index,
                 unsigned int number_nodes)
{
    if (root == NULL)
        return (true);
 
    if (index >= number_nodes)
        return (false);
 
    return (isComplete(root->left, 2*index + 1, number_nodes) &&
            isComplete(root->right, 2*index + 2, number_nodes));
}
TreeNode *newNode(char k)
{
    struct TreeNode *node = malloc(sizeof(TreeNode));
    node->val = k;
    node->right = node->left = NULL;
    return node;
}
int main(){
    TreeNode* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->right->right = newNode(6);
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;
    if (isComplete(root, index, node_count))
        printf("The Binary Tree is complete\n");
    else
        printf("The Binary Tree is not complete\n");
    return (0);
}
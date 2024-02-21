#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode
{
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

//    1    
//  2  3  
// 4 5 6 7
TreeNode n7 = {7, NULL, NULL};
TreeNode n6 = {6, NULL, NULL};
TreeNode n5 = {5, NULL, NULL};
TreeNode n4 = {4, NULL, NULL};
TreeNode n3 = {3, &n6, &n7};
TreeNode n2 = {2, &n4, &n5};
TreeNode n1 = {1, &n2, &n3};

void preorder(TreeNode* root) {
    if(root != NULL) {
        printf("%d\n", root ->data);
        preorder(root ->left);
        preorder(root ->right);
    }
}

void inorder(TreeNode* root) {
    if(root != NULL) {
        inorder(root ->left);
        printf("%d\n", root ->data);
        inorder(root ->right);
    }
}

void postorder(TreeNode* root) {
    if(root != NULL) {
        postorder(root ->left);
        postorder(root ->right);
        printf("%d\n", root ->data);
    }
}

int main(void) {
    printf("전위순회\n");
    preorder(&n1);
    printf("\n중위순회\n");
    inorder(&n1);
    printf("\n후위순회\n");
    postorder(&n1);
    return 0;
}
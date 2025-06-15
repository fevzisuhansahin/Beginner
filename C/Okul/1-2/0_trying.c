#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
int data;
struct node* left; struct node* right;
}NODE;

NODE* newNode(int data) {
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int ff(NODE* root){
    if(root == NULL)
        return 0;
    return (root->data + ff(root->right) - ff(root->left));
}

int main(){
    struct node *root = newNode(5);
    root->left = newNode(4);
    root->right= newNode(3);
    root->left->left= newNode(2);
    root->right->right= newNode(1);
    printf("%d",ff(root));
    return 0;
}
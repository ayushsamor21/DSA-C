#include <stdio.h>
#include <stdlib.h>

//Postorder Traversal : left->right->node

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createTree(int value){
    struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void printTree(struct Tree* root){
    if(root == NULL){
        return;
    }
    
    printTree(root->left);
    printTree(root->right);
    printf("%d->", root->data);

}

void freeTree(struct Tree* root) {
    if (root == NULL){
        return;
    }
    freeTree(root->left);
    freeTree(root->right);

    free(root);
}


int main(){
    int num1 = 10, num2 = 20, num3 = 30; 

    struct Tree* root = createTree(num1);
    struct Tree* left = createTree(num2);
    struct Tree* right = createTree(num3);


    root->left = left;
    root->right = right;

    printf("Postorder Traversal: ");
    printTree(root);
    printf("\n");

    freeTree(root);
    return 0;
}


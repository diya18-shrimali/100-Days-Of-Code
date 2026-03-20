#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Create new node */
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

/* Function to count leaf nodes */
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

/* Main function */
int main() {
    /*
        Example Tree:
              1
             / \
            2   3
           / \    
          4   5  
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int leafCount = countLeafNodes(root);

    printf("Number of leaf nodes: %d\n", leafCount);

    return 0;
}
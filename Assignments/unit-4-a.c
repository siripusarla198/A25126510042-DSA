/*A system stores unique integer identification numbers using a Binary Search Tree. Write a C
program to insert n values, display inorder, preorder and postorder traversals, search for a
specified value, and report whether it exists. Use the output to explain why inorder traversal
produces sorted values.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
void insert(struct Node** root, int value) {
    if (*root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
    } else if (value < (*root)->data) {
        insert(&((*root)->left), value);
    } else if (value > (*root)->data) {
        insert(&((*root)->right), value);
    }
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0; // Value not found
    }
    if (root->data == value) {
        return 1; // Value found
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}
int main() {
    struct Node* root = NULL;
    int n, value, searchValue;
    printf("Enter the number of values to insert: ");
    scanf("%d", &n);
    printf("Enter %d unique integer values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&root, value);
    }
    printf("Inorder traversal (sorted values): ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\nEnter a value to search: ");
    scanf("%d", &searchValue);
    if (search(root, searchValue)) {
        printf("Value %d exists in the tree.\n", searchValue);
    } else {
        printf("Value %d does not exist in the tree.\n", searchValue);
    }
    return 0;
}
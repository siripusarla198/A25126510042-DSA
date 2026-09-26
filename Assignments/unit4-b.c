/*Extend a Binary Search Tree program to support deletion. The program should create a BST,
delete a user-specified node, correctly handle nodes with zero, one and two children, and display
inorder traversal before and after deletion. Test the program separately for all three deletion cases.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void delete_with_zero_children(struct Node** root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        delete_with_zero_children(&((*root)->left), data);
        inorder(*root);
    } else if (data > (*root)->data) {
        delete_with_zero_children(&((*root)->right), data);
        inorder(*root);
    } else {
        // Node with zero children
        free(*root);
        *root = NULL;
    }
}
void delete_with_one_child(struct Node** root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        delete_with_one_child(&((*root)->left), data);
        inorder(*root);
    } else if (data > (*root)->data) {
        delete_with_one_child(&((*root)->right), data);
        inorder(*root);
    } else {
        // Node with one child
        struct Node* temp = *root;
        if ((*root)->left != NULL) {
            *root = (*root)->left;
        } else {
            *root = (*root)->right;
        }
        free(temp);
    }
}
void delete_with_two_children(struct Node** root, int data) {
    if (*root == NULL) {
        return;
    }
    if (data < (*root)->data) {
        delete_with_two_children(&((*root)->left), data);
        inorder(*root);
    } else if (data > (*root)->data) {
        delete_with_two_children(&((*root)->right), data);
        inorder(*root);
    } else {
        // Node with two children
        struct Node* temp = *root;
        struct Node* successor = temp->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        temp->data = successor->data;
        delete_with_two_children(&(temp->right), successor->data);
    }
}
int main() {
    struct Node* root = NULL;
    int n, value, deleteValue;
    printf("Enter the number of values to insert: ");
    scanf("%d", &n);
    printf("Enter %d unique integer values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(&root, value);
    }
    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");
    
    printf("Enter the value to delete: ");
    scanf("%d", &deleteValue);
    
    // Check if the node has zero, one or two children
    struct Node* temp = root;
    while (temp != NULL && temp->data != deleteValue) {
        if (deleteValue < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    
    if (temp == NULL) {
        printf("Value %d not found in the tree.\n", deleteValue);
        return 0;
    }
    
    if (temp->left == NULL && temp->right == NULL) {
        delete_with_zero_children(&root, deleteValue);
        printf("Deleted node with zero children.\n");
    } else if (temp->left == NULL || temp->right == NULL) {
        delete_with_one_child(&root, deleteValue);
        printf("Deleted node with one child.\n");
    } else {
        delete_with_two_children(&root, deleteValue);
        printf("Deleted node with two children.\n");
    }
    
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
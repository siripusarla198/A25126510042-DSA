/*A department maintains student roll numbers dynamically. Write a C program using a Singly
Linked List to create the list, insert at the beginning and end, search for a specified roll number,
delete a specified roll number, and display the updated list after each operation. Handle the case
when a requested roll number is not available.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int rollNumber;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int rollNumber) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNumber = rollNumber;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int rollNumber) {
    struct Node* newNode = createNode(rollNumber);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int rollNumber) {
    struct Node* newNode = createNode(rollNumber);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void searchRollNumber(int rollNumber) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->rollNumber == rollNumber) {
            printf("Roll number %d found in the list.\n", rollNumber);
            return;
        }
        temp = temp->next;
    }
    printf("Roll number %d not found in the list.\n", rollNumber);
}
void displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Current list of roll numbers: ");
    while (temp != NULL) {
        printf("%d -> ", temp->rollNumber);
        temp = temp->next;
    }
    printf("NULL\n");
}
void deleteRollNumber(int rollNumber) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->rollNumber != rollNumber) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Roll number %d not found in the list. Cannot delete.\n", rollNumber);
        return;
    }
    if (prev == NULL) {
        head = temp->next; 
    } else {
        prev->next = temp->next; 
    }
    free(temp);
    printf("Roll number %d deleted from the list.\n", rollNumber);
    displayList();
}
int main() {
    int choice, rollNumber;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search Roll Number\n");
        printf("4. Delete Roll Number\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter roll number to insert at beginning: ");
                scanf("%d", &rollNumber);
                insertAtBeginning(rollNumber);
                displayList();
                break;
            case 2:
                printf("Enter roll number to insert at end: ");
                scanf("%d", &rollNumber);
                insertAtEnd(rollNumber);
                displayList();
                break;
            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &rollNumber);
                searchRollNumber(rollNumber);
                break;
            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                deleteRollNumber(rollNumber);
                break;
            case 5:
                displayList();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
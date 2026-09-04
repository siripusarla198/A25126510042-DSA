/*Develop a C program for a Doubly Linked List representing a sequence of web pages visited by a
user. The program should insert a new page, move forward and backward, delete a specified
page, and display the pages from first-to-last and last-to-first while handling beginning and end
conditions correctly.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int pageNumber;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
struct Node* createNode(int pageNumber) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->pageNumber = pageNumber;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertPage(int pageNumber) {
    struct Node* newNode = createNode(pageNumber);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void moveForward() {
    if (head == NULL) {
        printf("No pages to move forward.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Moved forward to page number: %d\n", temp->pageNumber);
}
void moveBackward() {
    if (head == NULL) {
        printf("No pages to move backward.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp->prev != NULL) {
        temp = temp->prev;
    }
    printf("Moved backward to page number: %d\n", temp->pageNumber);
}
void deletePage(int pageNumber) {
    struct Node* temp = head;
    while (temp != NULL && temp->pageNumber != pageNumber) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Page number %d not found. Cannot delete.\n", pageNumber);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; 
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Page number %d deleted from the list.\n", pageNumber);
}
void displayPagesForward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("No pages to display.\n");
        return;
    }
    printf("Pages from first to last: ");
    while (temp != NULL) {
        printf("%d -> ", temp->pageNumber);
        temp = temp->next;
    }
    printf("NULL\n");
}
void displayPagesBackward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("No pages to display.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Pages from last to first: ");
    while (temp != NULL) {
        printf("%d -> ", temp->pageNumber);
        temp = temp->prev;
    }
    printf("NULL\n");
}
int main() {
    insertPage(1);
    insertPage(2);
    insertPage(3);
    displayPagesForward();
    moveForward();
    moveBackward();
    deletePage(2);
    displayPagesForward();
    displayPagesBackward();
    return 0;
}
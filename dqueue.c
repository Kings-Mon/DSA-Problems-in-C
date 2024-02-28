#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function prototypes
void insertAtBeginning(int value);
void insertAtLast(int value);
void insertAtRandomLocation(int value, int loc);
void deleteFromBeginning();
void deleteFromLast();
void deleteFromSpecifiedLocation(int loc);
void showDeque();
void reverseDeque();

int main() {
    int choice, value, loc;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at Last\n3. Insert at Random Location\n");
        printf("4. Delete from Beginning\n5. Delete from Last\n6. Delete Node from Specified Location\n");
        printf("7. Show\n8. Reverse\n9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtLast(value);
                break;

            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the location: ");
                scanf("%d", &loc);
                insertAtRandomLocation(value, loc);
                break;

            case 4:
                deleteFromBeginning();
                break;

            case 5:
                deleteFromLast();
                break;

            case 6:
                printf("Enter the location to delete: ");
                scanf("%d", &loc);
                deleteFromSpecifiedLocation(loc);
                break;

            case 7:
                showDeque();
                break;

            case 8:
                reverseDeque();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = front;
    newNode->prev = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }

    printf("Element inserted at the beginning.\n");
}

void insertAtLast(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element inserted at the last.\n");
}

void insertAtRandomLocation(int value, int loc) {
    if (loc <= 0) {
        printf("Invalid location. Location should be greater than 0.\n");
        return;
    }

    if (loc == 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* current = front;
    int i = 1;

    while (i < loc - 1 && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Invalid location. Cannot insert at the specified location.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }

    printf("Element inserted at location %d.\n", loc);
}

void deleteFromBeginning() {
    if (front == NULL) {
        printf("Deque is empty. Cannot delete from beginning.\n");
        return;
    }

    struct Node* temp = front;

    if (front->next != NULL) {
        front = front->next;
        front->prev = NULL;
    } else {
        front = rear = NULL;
    }

    free(temp);
    printf("Element deleted from the beginning.\n");
}

void deleteFromLast() {
    if (rear == NULL) {
        printf("Deque is empty. Cannot delete from last.\n");
        return;
    }

    struct Node* temp = rear;

    if (rear->prev != NULL) {
        rear = rear->prev;
        rear->next = NULL;
    } else {
        front = rear = NULL;
    }

    free(temp);
    printf("Element deleted from the last.\n");
}

void deleteFromSpecifiedLocation(int loc) {
    if (loc <= 0) {
        printf("Invalid location. Location should be greater than 0.\n");
        return;
    }

    if (front == NULL) {
        printf("Deque is empty. Cannot delete from specified location.\n");
        return;
    }

    struct Node* current = front;
    int i = 1;

    while (i < loc && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Invalid location. Cannot delete from the specified location.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        front = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        rear = current->prev;
    }

    free(current);
    printf("Element deleted from location %d.\n", loc);
}

void showDeque() {
    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node* current = front;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void reverseDeque() {
    if (front == NULL) {
        printf("Deque is empty.\n");
        return;
    }

    struct Node* current = front;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = front;
    front = rear;
    rear = temp;

    printf("Deque reversed.\n");
}


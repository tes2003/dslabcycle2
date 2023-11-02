#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head
void insertAtHead(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to insert a node at the tail
void insertAtTail(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to insert a node at a given position
void insertAtPosition(int data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertAtHead(data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of bounds.\n");
    } else {
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }
    }
}

// Function to delete a node from the head
void deleteAtHead() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
    }
}

// Function to delete a node from the tail
void deleteAtTail() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        if (current->prev != NULL) {
            current->prev->next = NULL;
        } else {
            head = NULL;
        }
        free(current);
    }
}

// Function to delete a node from a given position
void deleteAtPosition(int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deleteAtHead();
        return;
    }
    struct Node* current = head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of bounds.\n");
    } else {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    }
}

// Function to search for an element
int searchElement(int data) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

// Function to display the doubly linked list
void displayList() {
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, position, search;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at Head\n");
        printf("2. Insert at Tail\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Head\n");
        printf("5. Delete at Tail\n");
        printf("6. Delete at Position\n");
        printf("7. Search for an Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at head: ");
                scanf("%d", &data);
                insertAtHead(data);
                break;
            case 2:
                printf("Enter data to insert at tail: ");
                scanf("%d", &data);
                insertAtTail(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteAtHead();
                break;
            case 5:
                deleteAtTail();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &search);
                position = searchElement(search);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;
            case 8:
                displayList();
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

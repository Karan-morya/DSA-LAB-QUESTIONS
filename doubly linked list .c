#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert a node at the front of the Linked List
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Node inserted at the front.\n");
}

// Insert a node at the end of the Linked List
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node inserted at the end.\n");
}

// Delete the last node of the Linked List
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {  // Only one node
        free(temp);
        *head = NULL;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    printf("Last node deleted.\n");
}

// Delete the node before the specified position
void deleteBeforePosition(struct Node** head, int pos) {
    if (*head == NULL || pos <= 1) {
        printf("Invalid position or no node exists before the given position.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // Navigate to the node at the specified position
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->prev == NULL || temp->prev->prev == NULL) {
        printf("No node exists before the given position.\n");
        return;
    }
    
    struct Node* nodeToDelete = temp->prev;
    
    // Adjust pointers to bypass the node
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = temp;
    } else {  // If deleting the first node
        *head = temp;
    }
    temp->prev = nodeToDelete->prev;
    
    free(nodeToDelete);
    printf("Node before position %d deleted.\n", pos);
}

// Traversal of the Doubly Linked List
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to display the menu and handle operations
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Delete the last node\n");
        printf("4. Delete a node before a specified position\n");
        printf("5. Traverse the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Insert at front
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:  // Insert at end
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:  // Delete last node
                deleteLastNode(&head);
                break;
            case 4:  // Delete before position
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteBeforePosition(&head, pos);
                break;
            case 5:  // Traverse
                traverse(head);
                break;
            case 6:  // Exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

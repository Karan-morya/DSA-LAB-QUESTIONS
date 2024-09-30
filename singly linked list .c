#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the front of the Linked List
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
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
    }
    printf("Node inserted at the end.\n");
}

// Insert a node to keep the Linked List in ascending order
void insertInOrder(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted in order.\n");
}

// Delete the first node of the Linked List
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted.\n");
}

// Delete the node before the specified position
void deleteBeforePosition(struct Node** head, int pos) {
    if (*head == NULL || pos <= 1) {
        printf("Invalid position or no node exists before the given position.\n");
        return;
    }
    
    struct Node* temp = *head;
    struct Node* prev = NULL;
    
    if (pos == 2) {
        *head = temp->next;
        free(temp);
        printf("Node before position %d deleted.\n", pos);
        return;
    }
    
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL || prev == NULL || prev->next == NULL) {
        printf("No node exists before the given position.\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("Node before position %d deleted.\n", pos);
}

// Delete the node after the specified position
void deleteAfterPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after the given position.\n");
        return;
    }
    
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node after position %d deleted.\n", pos);
}

// Traversal of Linked List
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to display menu and perform operations
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Insert a node in ascending order\n");
        printf("4. Delete the first node\n");
        printf("5. Delete the node before a specified position\n");
        printf("6. Delete the node after a specified position\n");
        printf("7. Traverse the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertInOrder(&head, data);
                break;
            case 4:
                deleteFirstNode(&head);
                break;
            case 5:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteBeforePosition(&head, pos);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteAfterPosition(&head, pos);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

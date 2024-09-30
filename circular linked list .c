#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the Circular Linked List
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself (circular)
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Node inserted at the end.\n");
}

// Insert a node before a specified position
void insertBeforePosition(struct Node** head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        printf("List is empty, cannot insert at the specified position.\n");
        return;
    }
    if (pos == 1) {  // Inserting before the first node (new head)
        struct Node* temp = *head;
        while (temp->next != *head) {  // Traverse to the last node
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;  // Update head
    } else {
        struct Node* temp = *head;
        int count = 1;
        while (count < pos - 1 && temp->next != *head) {
            temp = temp->next;
            count++;
        }
        if (temp->next == *head && count != pos - 1) {
            printf("Position out of bounds.\n");
            free(newNode);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted before position %d.\n", pos);
}

// Delete the first node of the Circular Linked List
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == *head) {  // Only one node
        free(temp);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
    }
    printf("First node deleted.\n");
}

// Delete a node after a specified position
void deleteAfterPosition(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    int count = 1;

    while (count < pos && temp->next != *head) {
        temp = temp->next;
        count++;
    }
    if (temp->next == *head || temp->next->next == *head) {
        printf("No node to delete after the specified position.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node after position %d deleted.\n", pos);
}

// Traversal of the Circular Linked List
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function to display the menu and handle operations
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node at the end\n");
        printf("2. Insert a node before specified position\n");
        printf("3. Delete the first node\n");
        printf("4. Delete a node after specified position\n");
        printf("5. Traverse the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Insert at the end
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:  // Insert before specified position
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert before: ");
                scanf("%d", &pos);
                insertBeforePosition(&head, data, pos);
                break;
            case 3:  // Delete first node
                deleteFirstNode(&head);
                break;
            case 4:  // Delete node after specified position
                printf("Enter position after which to delete: ");
                scanf("%d", &pos);
                deleteAfterPosition(&head, pos);
                break;
            case 5:  // Traverse the list
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

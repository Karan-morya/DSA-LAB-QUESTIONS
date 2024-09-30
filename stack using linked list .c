#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
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

// Push operation to insert data into the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Element %d pushed onto the stack.\n", data);
}

// Pop operation to remove data from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Peek operation to return the top element without removing it
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Traversal operation to display all elements in the stack
void traverse(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver function to display the menu and handle stack operations
int main() {
    struct Node* top = NULL;  // Initialize the stack as empty
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push
                printf("Enter data to push onto the stack: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:  // Pop
                data = pop(&top);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:  // Peek
                data = peek(top);
                if (data != -1) {
                    printf("Top element: %d\n", data);
                }
                break;
            case 4:  // Traverse
                traverse(top);
                break;
            case 5:  // Exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

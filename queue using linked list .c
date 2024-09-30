#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the queue with front and rear pointers
struct Queue {
    struct Node *front, *rear;
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

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue operation to add an element to the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Element %d enqueued.\n", data);
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Element %d enqueued.\n", data);
}

// Dequeue operation to remove an element from the queue
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow! The queue is empty.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int dequeuedData = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return dequeuedData;
}

// Peek operation to return the front element without removing it
int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Traverse operation to display all elements in the queue
void traverse(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to display the menu and handle queue operations
int main() {
    struct Queue* q = createQueue();  // Create an empty queue
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Enqueue
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:  // Dequeue
                data = dequeue(q);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:  // Peek
                data = peek(q);
                if (data != -1) {
                    printf("Front element: %d\n", data);
                }
                break;
            case 4:  // Traverse
                traverse(q);
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

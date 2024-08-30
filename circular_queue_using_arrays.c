#include<stdio.h>
int maxsize = 10;
int que[10];
int front = -1, rear = -1;

void insert() {
    int key;
    if ((rear + 1) % maxsize == front) {
        printf("Queue overflow\n");
    } else {
        printf("Enter your element: ");
        scanf("%d", &key);
        if (rear == -1 && front == -1) {
            rear = 0;
            front = 0;
        } else {
            rear = (rear + 1) % maxsize;
        }
        que[rear] = key;
    }
}

void delete() {
    if (front == -1 && rear==-1) {
        printf("Queue is underflow\n");
    } else {
        printf("Deleted element: %d\n", que[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % maxsize;
        }
    }
}

void display() {
    if (front == -1 && rear== -1) {
        printf("Queue is empty\n");
    } else {
        int i;
        printf("Queue elements: ");
        for (i=front;i!=rear;(i=(i+1)%maxsize)){
            printf("%d ",que[i]);
        }
        printf("%d ",que[i]);
    }
}

int main() {
    int loc;
    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert an element in the queue\n");
        printf("2. Delete an element from the queue\n");
        printf("3. Display the queue elements\n");
        printf("Enter your choice (1-3), or press any other key to exit: ");
        scanf("%d", &loc);

        switch (loc) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            default:
                printf("Exiting...\n");
                loc = 0;  // Setting loc to 0 to exit the loop
                break;
        }
    } while (loc > 0 && loc < 4);

    return 0;
}

#include<stdio.h>
int maxsize = 10;
int stac[10];
int top=-1;

void insert() {
    int key;
    if(top==maxsize){
        printf("overwrite/overflow");
    }
    else{
        printf("Enter a element which can insert in stack:-");
        scanf("%d",&key);
        if(top==-1){
            top=0;
        }
        else{
            top++;
        }
        stac[top]=key;
    }
}

void delete() {
    int n;
    if(top==-1){
        printf("stack is underflow");
    }
    else{
        printf("Delete is element:-");
        n=stac[top];
        if(top==0){
            top=-1;
        }
        else{
           top--; 
        }
        printf("%d",n);
    }
}

void display() {
    if(top==-1){
        printf("stack is Empty");
    }
    else{
        printf("your stack element is:-");
        for(int i=top;i>-1;i--){
            printf("%d ",stac[i]);
        }
    }
}

int main() {
    int loc;
    do {
        printf("\nChoose an operation:\n");
        printf("1. Insert an element in the stack\n");
        printf("2. Delete an element from the stack\n");
        printf("3. Display the stack elements\n");
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

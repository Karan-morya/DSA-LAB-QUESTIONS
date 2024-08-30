#include<stdio.h>
int lock;
int arr[10];
int maxsize=10;
int front=0;
int rear=-1;
void insert(){
    int key;
    if(rear==maxsize){
        printf("overflow");
    }
    else{
        printf("Enter your number which can inser in array:-");
        scanf("%d",&key);
        rear++;
        arr[rear]=key;
        printf("%d",arr[rear]);
    }
}
void delete(){
    if(rear<front){
        printf("queue is empty\n");
        printf("underflow");
    }
    else{
        front++;
    }
}
void display(){
    if(rear<front){
        printf("queue is empty\n");
        printf("not show elements\n");
    }
    else{
        for (int i=front;i<=rear;i++){
            printf("%d ",arr[i]);
        }
    }
}
int main(){
do{
    printf("\nyou are insert an element in array then press 1\n");
    printf("you are delete an element in array then press 2\n");
    printf("you are display of array elements then press 3\n");
    scanf("%d",&lock);
    switch(lock){
        case(1):
          insert();
          break;
        case(2):
          delete();
          break;
        case(3):
          display();
          break;
        default:
           printf("chose correct number\n");
           printf("Exits");
           break;
    }
}while(0<lock && lock<4);
return 0;
}

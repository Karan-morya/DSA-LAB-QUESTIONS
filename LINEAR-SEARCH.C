#include<stdio.h>
#include<stdbool.h>
int main(){
    int num;
    printf("Enter a number while element delete in array:- ");
    scanf("%d",&num);

    int po;
    printf("enter a position of where insert element:-");
    scanf("%d",&po);

    int arr[11]={
        1,2,3,4,5,6,7,8,9,90
    };
    if(arr[po]==num){
        for (int i=po;i<=(sizeof(arr)/sizeof(int)-1);i++){
        arr[i]=arr[i+1];
        }
        for(int i=0;i<11;i++){
           printf("%d  ",arr[i]);
        }
    }
    else{
        printf("your inserted element not founded in at position");
    }
    
    return 0;
}

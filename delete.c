#include<stdio.h>
#include<stdbool.h>
int main(){
    char ch=false;
    int num;
    printf("enter a number which are you seek:-");
    scanf("%d",&num);
    int arr[10]={
        1,2,3,4,5,6,7,8,9,90
    };
    int start;
    int end = sizeof(arr)/sizeof(int)-1;
    int mid;
    int i=0;
    for (start=0;start<=end;i++){
        mid=start+end/2;
        printf("%d ",mid);
        if(arr[mid]==num){
            printf("Element is founded at index is:-%d",mid);
            ch=true;
            break;
        }
        else if(arr[mid]<num){
            start=mid+1;
        }
        else if(arr[mid]>num){
            end=mid-1;
        }
    }
    if(ch==false){
        printf("element is not founded in the array");
    }
}

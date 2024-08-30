#include<stdio.h>
int main(){
    int arr[10]={1,3,5,7,9};
    int brr[5]={2,4,6,8,10};
    for(int i=0;i<5;i++){
        arr[sizeof(brr)/sizeof(int)+i] = brr[i];
    }
    for (int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(arr[i]>arr[j]){
                continue;
            }
            else{
                int a=arr[j];
                arr[j]=arr[i];
                arr[i]=a;
            }
        }
    }
    for (int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}

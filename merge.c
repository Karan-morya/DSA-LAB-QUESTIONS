#include<stdio.h>
int main(){

    int arr1[10]={
        1,2,3,4,5
    };
    int arr2[5]={
        6,7,8,9,10
    };
    for (int i=0;i<=(sizeof(arr2)/sizeof(int)-1);i++){
        arr1[sizeof(arr1)/sizeof(int)+i]=arr2[i];
    }
    for (int i=0;i<=(sizeof(arr1)/sizeof(int)-1);i++){
        printf("%d",arr1[i])
    }
}

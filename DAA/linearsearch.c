#include<stdio.h>

int main(){
    int n;
    printf("enter the number of elements:");
    scanf("%d",&n);

    int arr[n];
    printf("enter the elements of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("enter the key element:");
    int key;
    scanf("%d",&key);

    for(int i=0;i<n;i++){
        if(key==arr[i]){
            printf("element found at index %d",i);
        }
    }

    return 0;
}
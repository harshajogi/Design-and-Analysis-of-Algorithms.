#include<stdio.h>

int main(){
    int n;

    printf("enter the no of elements:");
    scanf("%d",&n);

    int arr[n];
    printf("enter the array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("enter the key element:");
    scanf("%d",&key);

    int beg=0;
    int end=n-1;
    int mid=0;

    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==key){
            printf("found at %d",mid);
            break;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
}
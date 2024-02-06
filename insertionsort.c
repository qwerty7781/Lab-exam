#include<stdio.h>
#include<stdlib.h>

void insertionsort(int arr[],int size){
    int key,j;
    for(int i=1;i<size;i++){
         key=arr[i];
         j=i-1;
         while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
         }
         arr[j+1]=key;
    }
    for(int i=0;i<size;i++){
    printf("%d\t",arr[i]);
    }
}

void main(){
     int length,arr[100];
    printf("Enter the length of the array:");
    scanf("%d",&length);
    printf("Enter the numbers:");
    for(int i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,length);
}
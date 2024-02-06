#include<stdio.h>
#include<stdlib.h>

void selectionsort(int arr[],int size){
    int pos;
    for(int i=0;i<size-1;i++){
        pos=i;
        for(int j=i+1;j<size;j++){
            if(arr[pos]>arr[j]){
                pos=j;
            }
        }
        if(pos!=i){
            int temp=arr[pos];
            arr[pos]=arr[i];
            arr[i]=temp;
        }
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
    selectionsort(arr,length);

}
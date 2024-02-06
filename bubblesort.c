#include<stdio.h>
#include<stdlib.h>
void bubblesort(int arr[],int size){
    int j ,i;
    for(int i=0;i<size;i++){
    for(int j=0;j<size-i-1;j++){
        if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
for(int i=0;i<size;i++){
    printf("%d\t",arr[i]);
}
}
void main(){
    int length , arr[100];
    printf("Enter the length of the array:");
    scanf("%d",&length);
printf("Enter the numbers:");
for(int i=0;i<length;i++){
    scanf("%d",&arr[i]);
}
 bubblesort(arr,length);
}
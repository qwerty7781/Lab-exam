#include<stdio.h>
#include<stdlib.h>

#define length 20

int arr[length];
int front=-1;
int rear=-1;

void enqueue(){
    int data;
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    if(front==-1&&rear==-1){
        front=0;
        rear=0;
    }
    arr[rear]=data;
    rear= (rear+1)%length;

     if (rear==front){
        printf("The queue is full!...");
        exit(1);
     }

    for(int i=front;i<rear;i++){
        printf("\t%d",arr[i]);
    }
     
}

void dequeue(){
    int item;
    if (front==-1){
        printf("The queue is empty ");
        exit(1);
    }
    item=arr[front];
    front=front%length+1;
     if (front==rear){
        front=0;
        rear=0;
    }

    for(int i =front;i<rear;i++){
        printf("\n%d",arr[i]);
    }
    printf("\nThe deleted item is %d",item);
}

void main(){
    for(int i=1;i<=3;i++){
        printf("\n");
        enqueue();
    }
   printf("\nAfter deletion");
    
   dequeue();
   dequeue();
}
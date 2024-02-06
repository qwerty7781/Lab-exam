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
        arr[rear]=data;
    }

     else if (rear==length-1){
        printf("The queue is full!...");
     }
     else{
     rear=rear+1;
     arr[rear]=data;
     }

    for(int i=front;i<=rear;i++){
        printf("\t%d",arr[i]);
    }
     
}

void dequeue(){
    int item;
    if (front==-1){
        printf("The queue does not exist ");
        exit(1);
    }
    else if (front==rear){
         item =arr[front];
        front=0;
        rear=0;
    }
    else{
        item=arr[front];
        arr[front]=0;
        front=front+1;
    }
    
    for(int i =front;i<=rear;i++){
        printf("\n%d",arr[i]);
    }
    
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
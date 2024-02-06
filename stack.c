/*#include <stdio.h>
#include <stdlib.h> // Include for the exit function

#define length 10 // Define a maximum size for the stack

int stackarr[length];
int top = -1;

// Function to push an element onto the stack
void push()
{   
    int data;

    printf("Enter the data you want to push: ");
    scanf("%d", &data);

    if (top == length - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }

    top = top + 1;
    stackarr[top] = data;

    // Print the stack elements
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stackarr[i]);
    }
}

// Function to pop an element from the stack
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }

    
    top = top - 1;

    // Print the stack elements
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stackarr[i]);
    }
}

int main()
{
    int option;
    int choice;

    do
    {
        printf("Enter your choice: Press 1 for push and 2 for pop: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        default:
            printf("Invalid choice\n");
        }

        printf("Do you want to continue? Press 1 to continue and 0 to stop: ");
        scanf("%d", &option);
    } while (option != 0);

    return 0;
}
*/





#include<stdio.h>
#include<stdlib.h>

#define length 10
int arr[length];
int top=-1;

void push(){
    int data;
    printf("Enter the data to be pushed");
    scanf("%d",&data);

    if(top==length-1){
        printf("Stack overflow");
        exit(1);
    }
    top=top+1;
    arr[top]=data;

    for(int i=top;i>=0;i--){
        printf("%d",arr[i]);
    }
}

void pop(){
    if(top==-1){
        printf("Stack underflow");
        exit(1);
    }
    top=top-1;
    for(int i=top;i>=0;i--){
        printf("%d",arr[i]);
    }
}

void main(){
    int value;
    printf("Enter 1 for push 2 for pop:");
    scanf("%d",&value);
    if(value==1){
    push();
    }
    else{
        pop();
    }
    
}
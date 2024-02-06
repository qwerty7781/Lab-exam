#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
struct node* create_node(struct node*head ,int data){
    struct node*newNode=(struct node*)malloc(sizeof(struct node));
    newNode->link=NULL;
    newNode->data=data;
    if(head==NULL){
        head=newNode;
    }
    else{
        struct node*current = head;
        while(current->link!=NULL){
            current=current->link;
        }
        current->link=newNode;
        newNode->link=NULL;
    }
    return head;
    }
    struct node traversal(struct node*head){
    struct node*ptr=head;
    while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr=ptr->link;
    }
    }
    struct node*insertion(struct node*head){
        int data;
        struct node*newNode=NULL;
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data of the node that you want to insert:");
        scanf("%d",&newNode->data);
        newNode->link=head;
         head=newNode;
        return head;
    }
    struct node*insertion_at_end(struct node*head){
        int data;
        struct node*ptr=head;
        struct node*newNode=(struct node*)malloc(sizeof(struct node));
        newNode->link=NULL;
        printf("Enter the data of the node that you want to insert:");
        scanf("%d",&newNode->data);
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=newNode;
        newNode->link=NULL;
        return head;
    }
    struct node*insertion_at_any(struct node*head){
        struct node*ptr=head;
        int key;
         printf("enter the data after which you wnat to insert the data:");
         scanf("%d",&key);
         while(ptr!=NULL&&ptr->data!=key){
            ptr=ptr->link;
         }
         int data;
        struct node*newNode=(struct node*)malloc(sizeof(struct node));
        newNode->link=NULL;
        printf("Enter the data of the node that you want to insert:");
        scanf("%d",&newNode->data);
        newNode->link=ptr->link;
        ptr->link=newNode;
        return head;
    }
    struct node*deletion(struct node*head){
        struct node*ptr=head;
        printf("The data is deleting......\n");
        head=ptr->link;
        free(ptr);
        return head;
    }
    struct node*delete_at_end(struct node*head){
        struct node*ptr=head;
        struct node*ptr1;
        printf("the data is deleting at the end.......\n");
        while (ptr->link!=NULL){
            ptr1=ptr;
            ptr=ptr->link;
        }
        free(ptr);
        ptr1->link=NULL;
        return head;
    }
    struct node*delete_at_any(struct node*head){
        int key;
        struct node*ptr=head;
        struct node*ptr1;
        printf("Enter the data of the node that you want to delete:");
        scanf("%d",&key);
        while(ptr!=NULL&&ptr->data!=key){
            ptr1=ptr;
            ptr=ptr->link;
        }   
        ptr1->link=ptr->link;
        free(ptr);
        return head;
    }
void main(){
    struct node*head=NULL;
    int length,data;
    printf("enter the length of the nodes:");
    scanf("%d",&length);
    for(int i=1;i<=length;i++){
        printf("enter the data of %d node:",i);
        scanf("%d",&data);
        head=create_node(head,data);
    }
        int value;
        int choice;
    do{   
        printf("\nEnter 1 for TRAVERSAL:\nEnter 2 for INSERTION AT BEGENING:\nEnter 3 for INSERTION AT END:\nEnter 4 for INSERTION AT ANY POSITION:\nEnter 5 for DELETION AT BEGENING:\nEnter 6 for DELETION AT END:\nEnter 7 for DELETION AT END:\n ");
         printf("Enter your choice:");
         scanf("%d",&choice);
        switch (choice)
        {
        case 1: traversal(head);
        break;
        case 2:head= insertion(head);
        break;
        case 3:head= insertion_at_end(head);
        break;
        case 4:head= insertion_at_any(head);
        break;
        case 5:head= deletion(head);
        break;
        case 6:head= delete_at_end(head);
        break;
        case 7:head= delete_at_any(head);
        break;
        }
        printf("Do you want to continue 1(yes)/0(no):");
        scanf("%d",&value);
    }
    while(value!=0);
    }
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*left;
    struct node*right;
    int data;
};

struct node*create(){
    int data;
    printf("Enter the data of the node(-1 for no node):");
    scanf("%d",&data);
    struct node*newnode=malloc(sizeof(struct node));
    if(data==-1){
        return 0;
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;    
    printf("\n");
    printf("Enter the left child of %d :\n",data);
    newnode->left=create();
    printf("\n");
     printf("Enter the right child of %d :\n",data);
    newnode->right=create();

    return newnode;
    
}
struct node*search(struct node*root,int key){
    
    struct node*ptr=root;
    if(ptr->data!=key){
        if(ptr->left!=NULL){
       search(ptr->left,key);
    }
    else{
        return 0;
    }
    if(ptr->right!=NULL){
     search(ptr->right,key);
    }
    else{
        return 0;
    }
}
else{
    return ptr;
}
}

int  preorder(struct node*root){
        if(root==0){
            return 0;
        }
        else{
            printf("%d\t",root->data);
            preorder(root->left);
            preorder(root->right);
        }
}

void insertnode(struct node*ptr){
    char val;
    int data;
    if(ptr==NULL){
        printf("Search unsucessfull:no insertion");
        exit(0);
    }
    if(ptr->left==NULL||ptr->right==NULL){
        printf("Read option to insert as left or right(give option(L/R)):");
        scanf(" %c",&val);
        if(val=='L'){
            if(ptr->left==NULL){
                struct node*newnode=malloc(sizeof(struct node));
                printf("Enter the data to be inseted:");
                scanf("%d",&data);
                newnode->data=data;
                newnode->left=NULL;
                newnode->right=NULL;
                ptr->left=newnode;
            }
            else{
                printf("Insertion not possible...");
                exit(0);
            }
        }
        else{
            if(ptr->right==NULL){
                struct node*newnode=malloc(sizeof(struct node));
                printf("Enter the data to be inseted:");
                scanf("%d",&data);
                newnode->data=data;
                newnode->left=NULL;
                newnode->right=NULL;
                ptr->right=newnode;
            }
            else{
                printf("Insertion not possible...");
                exit(0);
            }

        }
    }
    else{
        printf("The key node alredy has child...");
    }

}

void main(){
    int key;
    struct node*root;
    root=create();
    printf("The tree has been created\n");
    printf("The preorder traversal is :");
    printf("\n");
    preorder(root);
    printf("\n");
     struct node*ptr;
      printf("Enter the key to be searched:");
        scanf("%d",&key);
     ptr=search(root,key);
     insertnode(ptr);
     preorder(root);

}
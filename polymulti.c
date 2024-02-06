#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node*link;
};
struct node*createnode(struct node*head,int coeff,int exp){
    struct node*newNode=NULL;
    newNode=malloc(sizeof(struct node));
    newNode->coeff=coeff;
    newNode->exp=exp;
    newNode->link=NULL;
    if(head==NULL){
        head=newNode;
    }   
    else{
        struct node*current=head;
        while(current->link!=NULL){
            current=current->link;
        }
        current->link=newNode;
        newNode->link=NULL;
    }
    return head;
}
struct node traverse(struct node*head){
    struct node*ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->coeff);
        ptr=ptr->link;       
    }
     printf("\n");
    ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->exp);
        ptr=ptr->link;
    }
    printf("\n");
   
}

struct node*multi(struct node*head1,struct node*head2){
    struct node*ptr1=head1;
    struct node*ptr2=head2;
    struct node*head3=NULL;
    int res1,res2;
    while(ptr1!=NULL){
         ptr2=head2;
        while(ptr2!=NULL){
            res1=ptr1->coeff*ptr2->coeff;
            res2=ptr1->exp+ptr2->exp;
            head3=createnode(head3,res1,res2);
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
       
    }
    return head3;
}

struct node*merge(struct node*head1,struct node*head2){
    struct node*ptr1=head1;
    while(ptr1->link!=NULL){
        ptr1=ptr1->link;
    }
    ptr1->link=head2;
    return head1;
}
struct node*addpoly(struct node*head3){
    struct node*ptr3=head3;
    struct node*ptr4=head3;
    struct node*prevNode=ptr4;
    struct node*temp=head3;
    while(ptr3!=NULL){            //in order to go to next node and check its coefficient and exponent with others 
       int coeffSum=ptr3->coeff;
       int exp=ptr3->exp;
        ptr4=ptr3->link;  //ptr4 onnu kooti which means if ptr3=1000 annel ptr4=2000 aaki
        while(ptr4!=NULL){
            prevNode=ptr4;
            if(exp==ptr4->exp){
                coeffSum=ptr4->coeff+coeffSum;
                prevNode->link=ptr4->link;
                free(ptr4);
                ptr4=prevNode->link;
                continue; //marakaruthhhh<3
            }
            ptr4=ptr4->link;
            
        }
        ptr3->coeff=coeffSum;
        ptr3=ptr3->link;
    }

    return head3;
}

struct node*sort(struct node*head){
    struct node*ptr=head;
    struct node*ptr2=ptr;
    while(ptr!=NULL){
        ptr2=ptr->link;
        while(ptr2!=NULL){
            if(ptr2->exp>ptr->exp){
                 int temp=ptr->exp;
                 ptr->exp=ptr2->exp;
                 ptr2->exp=temp;  
                 int temp1=ptr->coeff;
                 ptr->coeff=ptr2->coeff;
                 ptr2->coeff=temp1;
            }
            ptr2=ptr2->link;
        }
        ptr=ptr->link;
    }
    return head;
}

/*struct node*sort(struct node*head){
    struct node*ptr=head->link;
    struct node *ptr2=ptr;
    while(ptr!=NULL){
        ptr2=head;
        while(ptr2!=NULL){
            if(ptr2->link!=NULL){
            if(ptr2->exp<ptr2->link->exp){
                int temp=ptr2->exp;
                ptr2->exp=ptr2->link->exp;
                ptr2->link->exp=temp;
                int temp1=ptr2->coeff;
                ptr2->coeff=ptr2->link->coeff;
                ptr2->link->coeff=temp1;
            }
            }
            ptr2=ptr2->link;
        }
        ptr=ptr->link;
    }
    return head;
}
*/
/*struct node*sort(struct node*head){
    struct node*ptr=head;
    struct node*ptr2=ptr;
    for(ptr=ptr->link;ptr!=NULL;ptr=ptr->link){
        for(ptr2=head;ptr2!=NULL;ptr2=ptr2->link){
            if(ptr2->link!=NULL){
            if(ptr2->exp<ptr2->link->exp){
                int temp=ptr2->exp;
                ptr2->exp=ptr2->link->exp;
                ptr2->link->exp=temp;
                int temp1=ptr2->coeff;
                ptr2->coeff=ptr2->link->coeff;
                ptr2->link->coeff=temp1;
            }
            }
        }
    }
    return head;
}
*/

void main(){
    struct node*head1=NULL;
    struct node*head2=NULL;

    //FIRST POLYNOMIAL
    int coeff,exp,length; 
    printf("Enter the size of the first polynomial:\n");
    scanf("%d",&length);
    for(int i=1;i<=length;i++){
        printf("Enter the coefficient of %d term:",i);
        scanf("%d",&coeff);
        printf("Enter the exponent of the %d term:",i);
        scanf("%d",&exp);
        head1=createnode(head1,coeff,exp);
    }
    traverse(head1);
    //SECOND POLYNOMIAL
    int length2;
    printf("Enter the size of the second polynomial:\n");
    scanf("%d",&length2);
    for(int i=1;i<=length2;i++){
        printf("Enter the coefficient of %d term:",i);
        scanf("%d",&coeff);
        printf("Enter the exponent of the %d term:",i);
        scanf("%d",&exp);
        head2=createnode(head2,coeff,exp);
    }
    traverse(head2);
    struct node*head3=NULL;

    int choice;
        int key;
    do{
        
        printf("Enter 1:FOR POLYNOMIAL MULTIPLICATION \n Enter 2:FOR POLYNOMIAL ADDITION\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: head3 = multi(head1,head2);
                     printf("The polynomial after multiplication is:\n");
                     head3=addpoly(head3);
                     head3 =sort(head3);
                     traverse(head3); 
                     break;

            case 2: head3=merge(head1,head2);
                    printf("The polynomial after addition is:\n");
                    head3=addpoly(head3);
                    traverse(head3); 
                    break;    
                         
        }
        printf("Do you want to continue 1(yes)/0(no):");
                    scanf("%d",&key);
    }
        while(key!=0);
}
   
/*struct node*multi(struct node*head1,struct node*head2){
    struct node*ptr=head1;
    struct node*ptr1=head2;
    struct node*head3=NULL;
    int res1,res2;
    while(ptr!=NULL){
        ptr1=head2;
        while(ptr1!=NULL){
            res1=ptr->coeff*ptr1->coeff;
            res2=ptr->exp+ptr1->exp;
            head3=create(head3,res1,res2);
            ptr1=ptr->link;
        }
        ptr=ptr->link;
    }
    return head3;
}

struct node*createnode(struct node*head){
    struct node*newnode=NULL;
    newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=NULL;
    if(newnode==NULL){
        head=newnode;
    }
    else{
        struct node*current=head;
        while(current->link=NULL){
            current=current->link;
        }
        current->link=newnode;

    }

}

struct node*addpoly(struct node*head3){
    struct node*ptr=head3;
    struct node*ptr1=ptr;
    struct node*prevnode=ptr1;
    while(ptr!=NULL){
        sumcoeff=ptr->coeff;
        exponent=ptr->exp;
        ptr1=ptr->link;
        while(ptr1!=NULL){
            if(ptr1->exp==exponent){
                prevnode->link=ptr1->link;
                free(ptr1);
                ptr1=prevnode->link;
            }
            prevnode=ptr1;
            ptr1=ptr1->link
        }
        ptr->coeff=coeffsum;
        ptr=pre->link;
    }
    return head3;

}*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int arr[MAX];

void BuildTree(int i,int data){
    char val;
    int data1,data2;
    if(i!=-1){
        arr[i]=data;
        printf("The node %d has left subtree(Give option = Y/N):",data);
        scanf(" %c",&val);
        if(val=='Y'){
            printf("Enter the data of the node:");
            scanf("%d",&data1);
            BuildTree((2*i)+1,data1);
        }
        else{
            BuildTree(-1,-1);
        }
    
    printf("The node %d has right subtree(Give option = Y/N):",data);
    scanf(" %c",&val);
        if(val=='Y'){
            printf("Enter the data of the node:");
            scanf("%d",&data2);
            BuildTree((2*i)+2,data2);
        }
        else{
            BuildTree(-1,-1);
        }
    }
}
void display(){
    for(int i=0;i<MAX;i++){
    if(arr[i]!=0){
        printf("%d\t",arr[i]);
    }
    else{
        arr[i]=0;
    }
   }
}

int search(int index,int key){
    int i=index;
    if(arr[i]!=key){
        if((2*i)+1<MAX){
            search((2*i)+1,key);
        }
        else{ 
        if((2*i)+2<MAX){
            search((2*i)+2,key);
        }
        else{
            return -1;
        }
        }
        }
    else
    {
        return i;
    }
}

void insert(int l){
    int data;
    char val;
    printf("Enter the data to be inserted:");
    scanf("%d",&data);
   // if(l==-1){
   //     printf("seacrch unsucessfull:insertion not possible");
  //      exit(0);
   // }
    if(arr[(2*l)+1]==0||arr[(2*l)+2]==0){
        printf("Read option to read as left or right(Give option(L/R)):");
        scanf(" %c",&val);
        if(val=='L'){
            if(arr[(2*l)+1]==0){
                arr[(2*l)+1]=data;
            }
            else{
                printf("Desired insertion not possible...");
            }
        }
            if(val=='R'){
                if(arr[(2*l)+2]==0){
                    arr[(2*l)+2]=data;
                }
                else{
                    printf("Desired insertion not possible....");
                }
            }
    }
            else{
                printf("ITEM cannot be inserted as leaf node");
            }
            

        }




void main(){
    int n,key;
    printf("Enter the data of the root node:");
    scanf("%d",&n);
    BuildTree(0,n);
    display();
    printf("\n");
    printf("Enter the key to be searched:");
    scanf("%d",&key);
    int l=search(0,key);
    insert(l);
    display();
    

    

    
}

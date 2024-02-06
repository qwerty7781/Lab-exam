//bubble sort
#include<stdio.h>
void main(){
    int a[100],length;
    printf("Enter the length of the array:");
    scanf("%d",&length);
    printf("Enter the elements of the array:");
    for(int i=0;i<length;i++){
        scanf("%d",&a[i]);
    }
    //sorting the array....

    for(int i=0;i<length;i++){
        for(int j=0;j<length-i-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    //Printing the array...
    printf("The sorted elements are:");
    for(int i=0;i<length;i++){
        printf("%d\n",a[i]);
    }

    //binary serach...
    int key,mid;
    printf("Enter the key to be searched:");
    scanf("%d",&key);
    int high=length-1;
    int low=0;
    while(high>=low){
     mid=(high+low)/2;
      if(a[mid]==key){
        printf("The key is found at position%d",mid);
       int  temp=mid;
        while(mid>=0){
          mid--;
          if(a[mid]==key){
            printf("\nThe key is found at position:%d\t",mid);
          }
        }
         mid=temp;
        while(mid<=length-1){
          mid++;
          if(a[mid]==key){
          printf("\nThe key is found at position:%d\t",mid);
          }
        }
        break;
      }
      else if(mid<key){
        low=mid+1;
      }
      else{
        high=mid-1;
      }
    }
    
}
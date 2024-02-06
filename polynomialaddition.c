#include<stdio.h>
struct poly{
    int coeff;
    int exp;
};
void main(){
int length1,length2,i,j,k;
struct poly arr1[10], arr2[10],res[20];
printf("Enter the length of the first polynomial:");
scanf("%d",&length1);
printf("Enter the elements of the first polynomial:\n");
for(i=0;i<length1;i++){
    printf("Enter the coeff of %d term:",i+1);
    scanf("%d",&arr1[i].coeff);
    printf("Enter the expo of %d term:",i+1);
    scanf("%d",&arr1[i].exp);
}
printf("The elements of the first polynomial are :\n");
for(i=0;i<length1;i++){
    printf("%d\t",arr1[i].coeff);
}
  printf("\n");
  for(i=0;i<length1;i++){
    printf("%d\t",arr1[i].exp);
}
printf("\nEnter the length of the second polynomial:");
scanf("%d",&length2);
printf("Enter the elements of the second polynomial:\n");
for(i=0;i<length2;i++){
    printf("Enter the coeff of %d term:",i+1);
    scanf("%d",&arr2[i].coeff);
    printf("Enter the expo of %d term:",i+1);
    scanf("%d",&arr2[i].exp);
}
printf("The elements of the second polynomial are :\n");
for(i=0;i<length2;i++){
    printf("%d\t",arr2[i].coeff);
}
  printf("\n");
  for(i=0;i<length2;i++){
    printf("%d\t",arr2[i].exp);
}
i=j=k=0;
while(i<length1 && j<length2){
    if(arr1[i].exp>arr2[j].exp){
        res[k].coeff=arr1[i].coeff;
        res[k].exp=arr1[i].exp;
        i++;
    }
    else if(arr1[i].exp<arr2[j].exp){
        res[k].coeff=arr2[j].coeff;
        res[k].exp=arr2[j].exp;
        j++;
    }
    else{
        res[k].coeff=arr1[i].coeff+arr2[j].coeff;
        res[k].exp=arr1[i].exp;
        i++;
        j++;
    }
    k++;
}
while(i<length1){
    res[k].coeff=arr1[i].coeff;
    res[k].exp=arr1[i].exp;
    i++;
    k++;
}
while(j<length2){
    res[k].coeff=arr2[j].coeff;
    res[k].exp=arr2[j].exp;
    j++;
    k++;
}
printf("\nThe resulting polynomial is :\n");
for(i=0;i<k;i++){
    printf("%d\t",res[i].coeff);
}
printf("\n");
for(j=0;j<k;j++){
    printf("%d\t",res[j].exp);
}
} 
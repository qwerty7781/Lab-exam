#include<stdio.h>
#include<stdlib.h>

int partition(int arr[],int p,int r){
    int x=arr[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(arr[j]<=x){
            i=i+1;

            int swap=arr[i];
        arr[i]=arr[j];
        arr[j]=swap;
        }
    }
    int swap=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=swap;

    return i+1;
}

void quicksort(int arr[],int p,int r){
    if(p<r){
        int q=partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}

void main(){
     int length,arr[100];
    printf("Enter the length of the array:");
    scanf("%d",&length);
    printf("Enter the numbers:");
    for(int i=0;i<length;i++){
        scanf("%d",&arr[i]);
    }
    int p=0;
    quicksort(arr,p,length-1);
    
    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}




/*#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (arr[j] <= x) {
            i = i + 1;
            
            // Swap arr[i] and arr[j]
            int swap = arr[i];
            arr[i] = arr[j];
            arr[j] = swap;
        }
    }

    // Swap arr[i+1] and arr[r]
    int swap = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = swap;

    return i + 1;
}

void quicksort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int main() {
    int length, arr[100];
    printf("Enter the length of the array:");
    scanf("%d", &length);

    printf("Enter the numbers:");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    int p = 0;
    quicksort(arr, p, length - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
*/
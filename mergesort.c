#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int arr[MAX];

void merge(int low, int high, int middle, int arr[]);

void mergesort(int arr[], int l, int r) {
    int mid;
    if (l >= r) {
        return;
    } else {
        mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(l, r, mid, arr);
    }
}

void merge(int low, int high, int middle, int arr[]) {
    int i = low;
    int j = middle + 1;
    int k = 0;
    int temp[MAX];

    while (i <= middle && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++) {
        arr[low + m] = temp[m];
    }
}

int main() {
    int n;
    printf("Enter the length of the array:");
    scanf("%d", &n);

    printf("Enter the elements of the array:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n - 1);

    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}

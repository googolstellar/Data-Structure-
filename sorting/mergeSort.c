#include<stdio.h>

void merge(int arr[100], int left, int right){
    int mid = (left + right)/2;
    int i = left, j = mid+1, k = 0, tempArr[100];
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            tempArr[k] = arr[i];
            k++;
            i++;
        }
        else{
            tempArr[k] = arr[j];
            k++;
            j++;
        }
    } 
    while(i <= mid){
            tempArr[k] = arr[i];
            k++;
            i++;
    }
    while(j <= right){
            tempArr[k] = arr[j];
            k++;
            j++;
    }

    for(i = 0; i < k; i++){
        arr[left] = tempArr[i];
        left++;
    }
}

void mergeSort(int arr[100], int left, int right){
    int mid = (left + right)/2;
    if(left < right){
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, right);
    }
}

void display(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[100], i, n;
    printf("MERGE SORT\n");
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the number in the array: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    printf("The sorted array is: ");
    display(arr, n);
    return 0;
}
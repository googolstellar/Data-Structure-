#include<stdio.h>
#define MAX 100

int binSearch(int arr[], int left, int right, int n){
    int mid = (left + right)/2;
    if(left >= right){
        return arr[left] > n ? left : left + 1;
    }
    if(arr[mid] == n){
        return mid + 1;
    }
    if(arr[mid] < n){
        return binSearch(arr, mid + 1, right, n);
    }
    else if(arr[mid] > n){
        return binSearch(arr, left, mid - 1, n);
    }
}


void display(int arr[], int n){
    int i;
    printf("Sorted array is : ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int n){
    int i, j, val, k;
    for(i = 1; i < n; i++){
        val = arr[i];
        k = i - 1;
        j = binSearch(arr, 0, k, val);
        while(k >= j){
            arr[k + 1] = arr[k];
            k--;
        }
        arr[k+1] = val;
    }
}

int main(){
    int arr[MAX], i, n;
    printf("Enter the size of the array to be sorted : ");
    scanf("%d", &n);
    printf("Enter the numbers : ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    display(arr, n);
    return 0;
}
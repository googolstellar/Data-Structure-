#include<stdio.h>
int quickSwap(int arr[], int left, int right){
    int pivot = arr[left];
    int i = left, j = right+1;
    while(i < j){
        do{i++;}while(i<=right && arr[i] < pivot);
        do{j--;}while(arr[j] > pivot);
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[left] = arr[j];
    arr[j] = pivot;
    return j;
}

void quickSort(int arr[], int left, int right){
    if(left < right){
       int j = quickSwap(arr, left, right);
       quickSort(arr, left, j-1);
       quickSort(arr, j+1, right); 
    }
}

void display(int arr[], int n){
    printf("The sorted array is : ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[100], i, j, n;
    printf("Enter size of array ");
    scanf("%d", &n);
    printf("Enter the elements in the array \n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    quickSort(arr , 0, n - 1);
    display(arr, n);
    printf("\n");
}
#include<stdio.h>

void insertionSort(int arr[100], int n){
    int i, val, j;
    for(i = 1; i < n; i++){
        val = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > val){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
}

void display(int arr[100], int n){
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main (){
    int arr[100], i, n;
    printf("Enter no.s of terms in the array :");
    scanf("%d", &n);
    printf("Enter no.s in the array to be sorted:");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    printf("The sorted array is : ");
    display(arr, n);
    printf("\n");
    return 0;
}
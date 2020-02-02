#include<stdio.h>
void bubbleSort(int arr[100], int n){
    int i, j, temp;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[100], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[100], n;
    printf("Enter the no. of terms :");
    scanf("%d", &n);
    printf("Enter the terms in the array to be sorted :");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printf("The sorted array is : ");
    display(arr, n);
    printf("\n");
}
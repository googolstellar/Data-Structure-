//combining all sorting techniques
#include<stdio.h>
#define MAX 100

void selectionSort(int arr[], int n){
    int i, j, min, temp;
    for(i = 0; i < n; i++){
        min = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void insertionSort(int arr[], int n){
    int i, j, key;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j]; 
                j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int right){
    int mid = (left + right)/2;
    int i = left, j = mid + 1, temp[MAX], k = 0;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(i = 0; i < k; i++){
        arr[left++] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

void display(int arr[], int n){
    int i;
    printf("\nSorted array is : ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main (){
    int n, arr[MAX], choice;
    printf("Enter the size of array of numbers to be sorted: ");
    scanf("%d", &n);
    printf("Enter the numbers in the array \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
        
    printf("\n1. Selection Sort");
    printf("\n2. Insertion Sort");
    printf("\n3. Merge Sort");
    printf("\n4. Quick Sort");
    printf("\n5. Bubble Sort");
    printf("\n6. Exit");
    do{
        printf("\nNow enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                   selectionSort(arr, n); 
                   display(arr, n);
                   break;
            case 2:
                   insertionSort(arr, n); 
                   display(arr, n);
                   break;
            case 3:
                   mergeSort(arr, 0, n - 1);
                   display(arr, n);
                   break;
        }
    }
    while (choice <= 5);
    return 0;
}
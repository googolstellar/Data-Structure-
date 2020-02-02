#include<stdio.h>
void swap(int arr[100], int i, int minIndex){
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
}

void selection_sort(int arr[100], int n){
    int i, j, minInd = 0;
    for(i = 0; i < n; i++){
        minInd = i;
        for(j = i + 1; j < n; j++){
            if(arr[minInd] > arr[j])
                minInd = j;
        }
        swap(arr, i, minInd);
    }
}

int main(){
    int arr[100], n, i;
    printf("Enter size of array ");
    scanf("%d", &n);
    printf("Enter the element of the array ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    selection_sort(arr, n);
    printf("\nSorted array : ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
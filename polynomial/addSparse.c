#include<stdio.h>
typedef struct sparse_matrix
{
    int row;
    int col;
    int val;
} sparseMatrix;

void readMat(sparseMatrix spaMat[100], int row, int col){
    int i, j, k = 1, temp;
    for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                scanf("%d", &temp);
                if(temp){
                    spaMat[k].row = i;
                    spaMat[k].col = j;
                    spaMat[k].val = temp;
                    k++;
                }
            spaMat[0].val = k - 1;
            }
        }
}
void addMat(sparseMatrix spaMat1[100], sparseMatrix spaMat2[100], sparseMatrix spaMat3[100]){
    int i = 1, j = 1, k = 1;
    spaMat3[0].row = spaMat1[0].row;
    spaMat3[0].col = spaMat1[0].col;
    while(i <= spaMat2[0].val && j <= spaMat1[0].val){
        if(spaMat2[i].row > spaMat1[j].row){
            spaMat3[k] = spaMat1[j];
            k++; j++;
        }
        else if(spaMat2[i].row < spaMat1[j].row){
            spaMat3[k] = spaMat2[i];
            k++; i++; 
        }
        else if(spaMat2[i].row == spaMat1[j].row){
            if(spaMat2[i].col > spaMat1[j].col)
                spaMat3[k++] = spaMat1[j++];
            if(spaMat2[i].col < spaMat1[j].col)
                spaMat3[k++] = spaMat2[i++];
            else{
                spaMat3[k].row = spaMat1[j].row;
                spaMat3[k].col = spaMat1[j].col;
                spaMat3[k].val = spaMat2[j].val + spaMat1[j].val;
                k++; i++; j++;
            }
        }
    }
    while(i <= spaMat2[0].val){
        spaMat3[k++] = spaMat2[i++];
    }
    while(j <= spaMat1[0].val){
        spaMat3[k++] = spaMat1[i++];   
    }
    spaMat3[0].val = k--;
}
// void disMat(sparseMatrix spaMat[100]){
//     int i;
//     for(i = 0; i < spaMat[0].val; i++){
//         printf("%d %d %d", spaMat[i].row, spaMat[i].col, spaMat[i].val);
//         printf("\n");
//     }
// }
void disMat(sparseMatrix spaMat[100]){
    int k = 1;
    for(int i = 0; i < spaMat[0].row; i++){
        for(int j = 0; j < spaMat[0].col; j++){
            if(spaMat[k].row == i && spaMat[k].col == j)
                printf("%d ", spaMat[k++].val);
            else 
                printf("0 ");
        }
        printf("\n");
    }
}
int main (){
    sparseMatrix spaMat1[100], spaMat2[100], spaMat3[100];
    int i, j, k = 1, row, col, temp;
    printf("enter no. of rows and col in 1st sparse matrix :");
    scanf("%d%d", &row, &col);
    spaMat1[0].row = row;
    spaMat1[0].col = col;
    printf("\nEnter no.s in 1st sparse matrix ");
    readMat(spaMat1, row, col);
    printf("enter no. of rows and col in 1st sparse matrix :");
    scanf("%d%d", &row, &col);
    spaMat2[0].row = row;
    spaMat2[0].col = col;
    printf("\nEnter no.s in 2nd sparse matrix ");
    readMat(spaMat2, row, col);
    if(!(spaMat1[0].row == spaMat2[0].row && spaMat1[0].col == spaMat2[0].col)){
       printf("Matrix addition is not compatible...");
       return 0; 
    }
    addMat(spaMat1, spaMat2, spaMat3);
    printf("\n Resulting matrix is as follows \n");
    disMat(spaMat3);
}
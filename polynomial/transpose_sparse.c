#include<stdio.h>
typedef struct sparse_matrix
{
    int row;
    int col;
    int val;
} sparseMatrix;

void readMat(sparseMatrix spaMat[100], int row, int col){
    int i, j, k = 1, temp;
    spaMat[0].row = row;
    spaMat[0].col = col;
    for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                scanf("%d", &temp);
                if(temp){
                    spaMat[k].row = i+1;
                    spaMat[k].col = j+1;
                    spaMat[k].val = temp;
                    k++;
                }
            spaMat[0].val = k - 1;
            }
        }
}

void transpose(sparseMatrix spaMat[100], sparseMatrix tranSpaMat[100]){
    int i, j, k = 1;
    tranSpaMat[0].col = spaMat[0].row;
    tranSpaMat[0].row = spaMat[0].col;
    tranSpaMat[0].val = spaMat[0].val;
    for(i = 1; i <= spaMat[0].col; i++){
        for(j = 1; j <= spaMat[0].val; j++){
            if(spaMat[j].col == i){
                tranSpaMat[k].col = spaMat[j].row;
                tranSpaMat[k].row = spaMat[j].col;
                tranSpaMat[k++].val = spaMat[j].val;   
            }
        }
    }

}

void disMat(sparseMatrix spaMat[100]){
    int i;
    for(i = 0; i <= spaMat[0].val; i++){
        printf("%d %d %d", spaMat[i].row, spaMat[i].col, spaMat[i].val);
        printf("\n");
    }
}

int main (){
    sparseMatrix spaMat[100], TranSpaMat[100];
    int i, j, k = 1, row, col, temp;
    printf("enter no. of rows and col of sparse matrix :");
    scanf("%d%d", &row, &col);
    spaMat[0].row = row;
    spaMat[0].col = col;
    printf("\nEnter no.s in the sparse matrix ");
    readMat(spaMat, row, col);
    disMat(spaMat);
    transpose(spaMat, TranSpaMat);
    printf("\n Resulting matrix is as follows \n");
    disMat(TranSpaMat);
}
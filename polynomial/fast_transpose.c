//fast transpose
#include<stdio.h>
typedef struct spMat{
    int row;
    int col;
    int val;
} spMat;

void readMat(spMat sparse[100], int row, int col){
    int k = 1, temp;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &temp);
            if(temp){
                sparse[k].val = temp;
                sparse[k].col = j;
                sparse[k++].row = i;
            }
        }
    }
    sparse[0].row = row;
    sparse[0].col = col;
    sparse[0].val = --k;
}

void transpose(spMat sparse[100], spMat traSparse[100]){
    int rowInd[100], startPos[100], i, j, k, sum = 0;
    for(i = 0; i < sparse[0].val; i++){
        rowInd[i] = 0;
    }
    for(i = 0; i < sparse[0].val; i++){
        rowInd[sparse[i+1].col]++;
    }
    for(i = 0; i < sparse[0].val; i++){
        startPos[i] = sum;
        sum += rowInd[i];
    }

    traSparse[0].row = sparse[0].col;
    traSparse[0].col = sparse[0].row;
    traSparse[0].val = sparse[0].val;

    for(i = 1; i <= sparse[0].val; i++){
        k = startPos[sparse[i].col] + 1;
        traSparse[k].row = sparse[i].col;
        traSparse[k].col = sparse[i].row;
        traSparse[k++].val = sparse[i].val;
        startPos[sparse[i].col]++;
    }
}

void disMat(spMat traSparse[100]){
        int k = 1;
        printf("\n");
        for(int i = 0; i < traSparse[0].row; i++){
        for(int j = 0; j < traSparse[0].col; j++){
            if(i == traSparse[k].row && j == traSparse[k].col)
                printf("%d ", traSparse[k++].val);
            else
                printf("0 ");
        }
        printf("\n");
    }

}

int main(){
    spMat sparse[100], traSparse[100];
    int row, col;
    printf("Enter no. of rows and columns of the matrix whose transpose you want");
    scanf("%d%d", &row, &col);
    printf("Enter number in the matrix");
    readMat(sparse, row, col);
    transpose(sparse, traSparse);
    disMat(traSparse);
    return 0;
}
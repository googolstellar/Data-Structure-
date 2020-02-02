//exponent based representation using matrix 
#include<stdio.h>
int readPoly(int poly[2][100]){
    int i = 0, tempCoeff, tempExp;
    do{
        scanf("%d", &tempCoeff);
        scanf("%d", &tempExp);
        if(tempCoeff != 0){
            poly[0][i] = tempCoeff;
            poly[1][i] = tempExp;
            i++;
        }
    }
    while(tempExp != 0);
    return i;
}

int addPoly(int poly1[2][100], int poly2[2][100], int poly3[2][100], int n1, int n2){
    int i = 0, j = 0, k = 0;
    while(i!= n1 && j!= n2){
        if(poly1[1][i] == poly2[1][j]){
            poly3[0][k] = poly1[0][i] + poly2[0][j];
            poly3[1][k] = poly1[1][i];
            k++;i++;j++;
        }
        else if(poly1[1][i] > poly2[1][j]){
           poly3[1][k] = poly1[1][i]; 
           poly3[0][k] = poly1[0][i];
           k++;i++; 
        }
        else if(poly1[1][i] < poly2[1][j]){
           poly3[1][k] = poly2[1][j]; 
           poly3[0][k] = poly2[0][j];
           k++;j++; 
        }
    }
    while(i < n1){
       poly3[1][k] = poly1[1][i]; 
       poly3[0][k] = poly1[0][i];
       k++;i++; 
    }
    while(j < n2){
        poly3[1][k] = poly2[1][j]; 
        poly3[0][k] = poly2[0][j];
        k++;j++;  
    };
    return k;
}

void disPoly(int poly[2][100], int n){
    int i, flag = 0;
    printf("The resulting polynomial is (coeff, exp): ");
    for(i = 0; i < n; i++){
        if(poly[0][i] != 0){
            flag = 1;
            printf("(%d, %d)", poly[0][i], poly[1][i]);
        }
    }
    if(flag == 0){
        printf("(0, 0)\n");
    }
}

int main (){
    int poly1[2][100], poly2[2][100], poly3[2][100], n1, n2, n3;
    printf("enter coefficent and exponent of first poly ");
    n1 = readPoly(poly1);
    printf("enter coefficent and exponent of second poly ");
    n2 = readPoly(poly2);
    n3 = addPoly(poly1,poly2, poly3, n1, n2);
    disPoly(poly3, n3);
    return 0;
}
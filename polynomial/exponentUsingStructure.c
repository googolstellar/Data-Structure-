#include<stdio.h>
typedef struct term
{
    int coeff;
    int exp;
} term;

int readPoly(term poly[100]){
    int tempCoeff, tempExp, i = 0, n = 0;
    do{
            scanf("%d%d", &tempCoeff, &tempExp);
            if(tempCoeff != 0){
                poly[n].coeff = tempCoeff;
                poly[n].exp = tempExp;
                n++;
            }
        }
        while(tempExp != 0);
    return n;
}

int addPoly(term poly1[100], term poly2[100], term poly3[100], int n1, int n2){
    int i = 0, j = 0, k = 0;
    while(i != n1 && j != n2){
        if(poly1[i].exp == poly2[j].exp){
            poly3[k].exp = poly1[i].exp;
            poly3[k++].coeff = poly1[i++].coeff + poly2[j++].coeff;
        }
        else if(poly1[i].exp > poly2[j].exp){
            poly3[k].exp = poly1[i].exp;
            poly3[k++].coeff = poly1[i++].coeff;        
        }
        else{
            poly3[k].exp = poly2[j].exp;
            poly3[k++].coeff = poly2[j++].coeff;        
        }
    }
    return k;
}

void disPoly(term poly[100], int k){
    int i;
    printf("The addition of two polynomial is (coeff, exp): ");
    for(i = 0; i < k; i++){
        printf("(%d, %d)", poly[i].coeff, poly[i].exp);
    }
}


int main (){
    term poly1[100], poly2[100], poly3[100];
    int n1, n2, i, k;
    printf("enter the details of polynomial to be added : \n");
    printf("enter coefficent and exponent of the first polynomial in decreasing order");
    n1 = readPoly(poly1);
    printf("enter coefficent and exponent of the second polynomial in decreasing order");
    n2 = readPoly(poly2);  
     //add
    k = addPoly(poly1, poly2, poly3, n1, n2);
    //print resulting polynomial
    disPoly(poly3, k);
    return 0;
}

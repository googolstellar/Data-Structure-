//Exponent based representation of polynomial
#include<stdio.h>
#define MAX 100

typedef struct{
    int coeff[MAX];
    int exp[MAX];
    int term;
}polynomial;

polynomial readPoly(){
    polynomial poly;
    printf("Enter the no. of terms: ");
    scanf("%d", &poly.term);
    printf("Enter the coefficent and exponent in pair:\n");
    for(int i = 0; i < poly.term; i++){
        scanf("%d %d", &poly.coeff[i], &poly.exp[i]);
    }
    return poly;
}

polynomial addPoly(polynomial poly1, polynomial poly2){
    int i = 0, j = 0, k = 0;
    polynomial poly3;
    while(i < poly1.term && j < poly2.term){
        if(poly1.exp[i] > poly2.exp[j]){
            poly3.exp[k] = poly1.exp[i];
            poly3.coeff[k] = poly1.coeff[i];
            i++; k++;
        }
        else if(poly2.exp[j] > poly1.exp[i]){
            poly3.exp[k] = poly2.exp[j];
            poly3.coeff[k] = poly2.coeff[j];
            j++; k++;   
        }
        else if(poly1.exp[i] == poly2.exp[j]){
            poly3.exp[k] = poly1.exp[i];
            poly3.coeff[k++] = poly1.coeff[i++] + poly2.coeff[j++];        
        }
    }
    while(i < poly1.term){
        poly3.exp[k] = poly1.exp[i];
        poly3.coeff[k] = poly1.coeff[i];
        i++; k++;
    }
    while(j < poly2.term){
        poly3.exp[k] = poly2.exp[j];
        poly3.coeff[k] = poly2.coeff[j];
        j++; k++; 
    }
    poly3.term = k;
    return poly3;
}

void display(polynomial poly){
    printf("The addition of two polynomial is:(exponent, coefficent)\n");
    for(int i = 0; i < poly.term; i++){
        printf("(%d, %d) ", poly.exp[i], poly.coeff[i]);
    }
    printf("\n");
}

int main (){
    polynomial poly1, poly2, poly3;
    printf("Enter details of 1st polynomial:\n");
    poly1 = readPoly();
    printf("Enter details of 2nd polynomial:\n");
    poly2 = readPoly();
    poly3 = addPoly(poly1, poly2);
    display(poly3);
    return 0;
}
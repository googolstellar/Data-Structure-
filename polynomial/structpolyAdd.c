#include<stdio.h>

typedef struct polynomial{
    int exp[100];
    int coeff[100];
    int n;
} polynomial;

polynomial readPoly(polynomial poly){
    printf("enter no. of terms: ");
    scanf("%d", &poly.n);
    for(int i = 0; i < poly.n; i++){
        printf("Enter exponent: ");
        scanf("%d", &poly.exp[i]);
        printf("Enter coefficent: ");
        scanf("%d", &poly.coeff[i]);
    }
    return poly;
}

// void addPoly(polynomial poly1, polynomial poly2, polynomial poly3){
//     int i = 0, j = 0, k = 0;
//     while(i < poly1.n && j < poly2.n){
//         if(poly1.exp[i] > poly2.exp[j]){
//             poly3.exp[k] = poly1.exp[i];
//             poly3.coeff[k] = poly1.coeff[i];
//             i++;
//             k++;
//         }
//         else if(poly1.exp[i] < poly2.exp[j]){
//             poly3.exp[k] = poly2.exp[j];
//             poly3.coeff[k] = poly2.coeff[j];
//             j++;
//             k++;
//         }   
//         else{
//             poly3.exp[k] = poly1.exp[i];
//             poly3.coeff[k] = poly1.coeff[i] + poly1.coeff[j];
//             j++;
//             i++;
//             k++;  
//         }
//     }

//     while(i < poly1.n){
//         poly3.exp[k] = poly1.exp[i];
//         poly3.coeff[k] = poly1.coeff[i];
//         i++;
//         k++;
//     }
//     while(j < poly1.n){
//         poly3.exp[k] = poly2.exp[j];
//         poly3.coeff[k] = poly2.coeff[j];
//         j++;
//         k++;
//     }
//     poly3.n = k - 1;
// }

void disPoly(polynomial poly){
    printf("(coefficent, exponent)\n");
    printf("%d ", poly.n);
    for(int i = 0; i < poly.n; i++){
        printf("(%d , %d) ", poly.coeff[i], poly.exp[i]);
    }
}

int main (){
    polynomial poly1, poly2, poly3;
    printf("Enter the details of polynomial to be added :");
    printf("\nDetails for poly 1 \n");
    poly1 = readPoly(poly1);
    // printf("\nDetails for poly 2 \n");
    // readPoly(poly2);
    // addPoly(poly1, poly2, poly3);
    // printf("The addition of two polynomial is :");
    disPoly(poly1);
}
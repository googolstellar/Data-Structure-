#include<stdio.h>
#include <stdlib.h>
int readPoly(int poly[100]){
    int deg, i;
    printf("\nEnter polynomial degree ");
    scanf("%d", &deg);
    printf("enter coefficents ");
    for(i = 0; i <= deg; i++){
        scanf("%d", &poly[i]);
    }
    return deg;
}

int addPoly(int poly1[100], int poly2[100], int deg1, int deg2, int poly3[100]){
    int diff = deg1 - deg2, i, deg3, j;
    if(diff > 0){
        deg3 = deg1;
        for(i = 0; i < diff; i++)
            poly3[i] = poly1[i];
        for(j = 0; j <= deg2; j++){
            poly3[i++] = poly1[i] + poly2[j];
        }
    }
    else if(diff < 0){
        deg3 = deg2;
        for(i = 0; i < abs(diff); i++)
            poly3[i] = poly2[i];
        for(j = 0; j <= deg1; j++){
            poly3[i++] = poly1[j] + poly2[i];
        }

    }
    else{
        int temp, flag = 0; 
        for(i = 0, j = 0; i <= deg1; i++){
            temp = poly1[i] + poly2[i];
            if(temp != 0){
                flag = 1;
            }
            if(flag){
                poly3[j++] = temp;
            }
        }
        deg3 = j-1;
    }
    return deg3;
}

void disPoly(int poly[100], int deg){
    int i ;
    for(i = 0; i <= deg; i++)
        printf("%d ", poly[i]);

}

int main (){
    int poly1[100], poly2[100], poly3[100], deg1, deg2, deg3;
    printf("Enter details of 1st polynomial ");
    deg1 = readPoly(poly1);
    printf("Enter details of 2nd polynomial ");
    deg2 = readPoly(poly2);
    deg3 = addPoly(poly1, poly2, deg1, deg2, poly3);
    printf("The result is : ");
    disPoly(poly3,deg3);
    return 0;
}

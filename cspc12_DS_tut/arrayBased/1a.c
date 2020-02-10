//Addition of polnomials using degree based representation
//currently working for +deg, can be extended for negative
//result could be displayed more dramatically
#include<stdio.h>
#define MAX 100

//funciton to read polynomial
int readPoly(int poly[MAX]){
    int deg, i;
    printf("Enter degree of polynomial: ");
    scanf("%d", &deg);
    printf("Enter coefficents of polynomial: ");
    for(i = 0; i <= deg; i++){
        scanf("%d", &poly[i]);
    }
    return deg;
}

//funciton to add polynomial
int addPoly(int poly1[MAX], int deg1, int poly2[MAX], int deg2, int poly3[MAX]){
    int i = 0, j = 0, k = 0;
    int diff = deg1 - deg2;
    if(diff > 0){
        while(diff){
            poly3[k++] = poly1[i++];
            diff--;
        }
    }
    else if(diff < 0){
        while(diff){
            poly3[k++] = poly2[j++];
            diff--;
        }
    }
    while(i <= deg1 && j <= deg2){
        poly3[k++] = poly1[i++] + poly2[j++];
    }
    return k-1;
}

//function to display plynomial
void display(int poly[MAX], int deg){
    printf("The result of addition of two polynomial is:\n");
    for(int i = 0; i <= deg; i++){
        printf("%d ", poly[i]);
    }
}

int main(){
    int poly1[MAX], poly2[MAX], poly3[MAX];
    int deg1, deg2, deg3, i;
    //read polynomial
    printf("Enter details of 1st polynomial:\n");
    deg1 = readPoly(poly1);
    printf("Enter details of 2nd polynomial:\n");
    deg2 = readPoly(poly2);    
    //addition of polynomial
    deg3 = addPoly(poly1, deg1, poly2, deg2, poly3);
    display(poly3, deg3);
    return 0;
}
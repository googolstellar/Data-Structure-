#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;

node * createll() {
    node *start = NULL, *temp = NULL, *last = NULL;
    int val;
    printf("Enter values in linkedlist(-1 meaning exit)");
    scanf("%d", &val);
    while(val != -1) {
        if(start == NULL) {
            start = (node *)malloc(sizeof(node));
            start->data = val;
            start->next = NULL;
            last = start;
        }
        else {
            temp = (node *)malloc(sizeof(node));
            temp->data = val;
            temp->next = NULL;
            last->next = temp;
            last = last->next;
        }
        scanf("%d", &val);
    }
    return start;
}

int countll(node *t) {
    if(t == NULL)
        return 1;
    else {
        t = t->next;
        return 1 + countll(t);
    } 
}

int searchll(node *t, int val) {
    if(t == NULL)
        return 0;
    else if(t->data == val)
        return 1;
    else return searchll(t->next, val);
}

void display(node *t){
    while(t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
}

void skipAdd(node *start, int *osum, int *esum) {
    // node *ostart = start, *estart = start->next;
    node *ostart, *estart;
    if(start == NULL) {
        ostart = estart = NULL;
    }
    else {
        ostart = start;
        estart = start->next;
    }
    while(estart != NULL) {
        *esum += estart->data;
        *osum += ostart->data;
        if(estart->next != NULL) {
            ostart = ostart->next->next;
            estart = estart->next->next;
        }
        else {
            estart = NULL;
            ostart = NULL;
        }
    }
    if(ostart != NULL) {
        *osum += ostart->data;
    }
}

int main () {
    node *start = createll();
    display(start);
    printf("\n");
    int val;
    // scanf("%d", &val);
    // if(searchll(start, val))
    //     printf("The no. is present.\n");
    // else
    //     printf("The no. is not present.\n");

    int osum = 0, esum = 0;
    skipAdd(start, &osum, &esum);
    printf("The sum of odd nodes are: %d", osum);
    printf("\nThe sum of even nodes are: %d\n", esum);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define NOT_FOUND -9999 //not found
#define ERROR -10000 //invalid operation
typedef struct node {
    int data;
    struct node *next;
} node;

node* createll() {
    int val;
    node *start, *temp, *last;
    scanf("%d", &val);
    if(val != -1) {
        start = (node*)malloc(sizeof(node));
        start->data = val;
        start->next = NULL;
        last = start;
    }
    else {
        start = NULL;
        return start;
    }
    do {
        scanf("%d", &val);
        if(val != -1) {
            temp = (node*)malloc(sizeof(node));
            temp->data = val;
            temp->next = NULL;
            last->next = temp;
            last = temp;
        }
        else {
            break;
        }
    }
    while(val != -1);
    return start;
}

void deleteAfterValue(node *start, int val1, int *val2) {
    node *t = start, *temp;
    // while(t->data != val1 && t != NULL) { //wrong as when t becomes null, it still checks t->data of a null
    while(t != NULL && t->data != val1) {
        t = t->next;
    }
    if(t == NULL) {
        *val2 = NOT_FOUND;
        return;
    }
    if(t->next == NULL) {
        *val2 = ERROR;
        return;
    }
    temp = t->next;
    t->next = temp->next;
    *val2 = temp->data;
    free(temp);
    return;
}

void display(node * start) {
    node *temp = start;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main () {
    node *start;
    printf("Enter the val for linkedlist(till -1 entered):\n");
    start = createll();
    printf("The Entered linkedlist is: ");
    display(start);
    //deleting after a value
    int val1, val2;
    printf("Enter the value after which You wanna delete: ");
    scanf("%d", &val1);
    deleteAfterValue(start, val1, &val2);
    if(val2 == NOT_FOUND) {
        printf("No such Value exists!\n");
    }
    else if(val2 == ERROR) {
        printf("Invalid Operation!\n");
    }
    else{
        printf("Successful Deletion!\n");
        printf("The deleted value: %d\n", val2);
    }
    return 0;
}
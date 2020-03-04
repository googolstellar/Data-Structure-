#include<stdio.h>
#include<stdlib.h>
#define NOT_FOUND 9999
#define ERROR 10000

typedef struct dllnode{
    int data;
    struct dllnode *blink, *flink;
} dllnode;

//creating a doubly linkedlist
dllnode* createdll() {
    int val;
    dllnode *temp, *start, *last;
    scanf("%d", &val);
    if(val != -1) {
        start =(dllnode*)malloc(sizeof(dllnode));
        start->data = val;
        start->blink = NULL;
        start->flink = NULL;
        last = start;
    }
    else {
        start = NULL;
        return start;
    }
    do{
        scanf("%d", &val);
        if(val != -1) {
            temp = (dllnode*)malloc(sizeof(dllnode));
            temp->data = val;
            temp->blink = last;
            last->flink = temp;
            temp->flink = NULL;
            last = temp;
        }
        else{
            return start;
        }
    }
    while(val != -1);
    return start;
}

//insertion on doubly linkedlist

//insertion after a value
void insertAfter(dllnode *start, int val1, int *val2) {
    dllnode *t = start, *temp;
    // *val2 = 0;
    //val1: after which to insert
    //*val2: which val to insert
    if(t == NULL) {
        *val2 = NOT_FOUND;
        return;
    }
    while(t != NULL && t->data != val1) {
        t = t->flink;
    }
    if(t != NULL) {
        temp = (dllnode*)malloc(sizeof(dllnode));
        temp->data = *val2;
        if(t->flink == NULL) {
            temp->flink = t->flink;
            t->flink = temp;
            temp->blink = t;
            return;
        }
        temp->flink = t->flink;
        temp->flink->blink = temp;
        temp->blink = t;
        t->flink = temp;
    }
    else{
        *val2 = NOT_FOUND;
    }
}

//insertion before a value
dllnode* insertBefore(dllnode *start, int val1, int *val2) {
    dllnode *t = start, *temp;
    if(t == NULL) {
        *val2 = NOT_FOUND;
        return start;
    }
    while(t != NULL && t->data != val1) {
        t = t->flink;
    }
    if(t != NULL) {
        temp = (dllnode*)malloc(sizeof(dllnode));
        temp->data = *val2;
        if(t->blink == NULL) {
            temp->flink = t;
            t->blink = temp;
            temp->blink = NULL;
            start = temp;
        }
        else{
            temp->blink = t->blink;
            t->blink->flink = temp;
            temp->flink = t;
            t->blink = temp;
        }
    }
    else{
        *val2 = NOT_FOUND;
    }
    return start;
}

//insertion at a particular position
dllnode* insertAt(dllnode *start, int val1, int pos, int *valid) {
    dllnode *temp, *t = start;
    if(pos == 1) {
        temp = (dllnode*)malloc(sizeof(dllnode));
        temp->data = val1;
        temp->flink = t;
        temp->blink = t->blink;
        t->blink = temp;
        start = temp;
    }
    else {
        int p = pos - 2;
        if(p <= 0) {
            *valid = ERROR;
            return start;
        }
        while(t!= NULL && p > 0) {
            p--;
            t = t->flink;
        }
        if(t == NULL){
            *valid = ERROR;
            return start;
        }

        temp = (dllnode*)malloc(sizeof(dllnode));
        temp->data = val1;
        if(t->flink == NULL) {
            t->flink = temp;
            temp->blink = t;
            temp->flink = NULL;
        }
        else{
            temp->flink = t->flink;
            t->flink->blink = temp;
            t->flink = temp;
            temp->blink = t;
        }
    }
    return start;
}

//forward display of linkedlist
void displayForward(dllnode *start) {
    dllnode *temp = start;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->flink;
    }
}

//backward display of linkedlist
void displayBackward(dllnode *start){
    dllnode *temp = start;
    if(start == NULL) {
        return;
    }
    while(temp->flink != NULL){
        temp = temp->flink;
    }
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->blink;
    }
}

int main () {
    printf("Enter the value in linkedlist: ");
    dllnode *start = createdll();
    int val1, val2;
    
    // printf("Enter the value to be inserted: ");
    // scanf("%d", &val2);
    // printf("Enter the value after which to insert: ");
    // scanf("%d", &val1);
    // insertAfter(start, val1, &val2);
    // if(val2 == NOT_FOUND) {
    //     printf("Value not found!\n");
    // }
    // else {
    //     printf("The doublylinked list\n");
    //     printf("In forward direction: ");
    //     displayForward(start);
    //     printf("\nIn backward direction: ");
    //     displayBackward(start);
    //     printf("\n");
    // }

    // printf("Enter the value before which to insert: ");
    // scanf("%d", &val1);
    // start = insertBefore(start, val1, &val2);
    // if(val2 == NOT_FOUND) {
    //     printf("Value not Found!\n");
    // }
    // else{
    //     printf("The doublylinked list\n");
    //     printf("In forward direction: ");
    //     displayForward(start);
    //     printf("\nIn backward direction: ");
    //     displayBackward(start);
    //     printf("\n");  
    // }
    int pos, valid;
    printf("Enter the postion at which to be inserted: ");
    scanf("%d", &pos);
    printf("Enter the value to insert: ");
    scanf("%d", &val1);
    start = insertAt(start, val1, pos, &valid);
    if(valid == ERROR){
        printf("Invalid Position!\n");
    }
    else{
        printf("The doublylinked list\n");
        printf("In forward direction: ");
        displayForward(start);
        printf("\nIn backward direction: ");
        displayBackward(start);
        printf("\n");         
    }
    return 0;
}
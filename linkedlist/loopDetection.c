#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node * createLoopll() {
    node *temp, *start = NULL, *last;
    int i = 5;
    while(i--) {
        temp = (node*)malloc(sizeof(node));
        temp->data = 5 - i;
        temp->next = NULL;
        if(start == NULL){
            start = temp;
            last = start;
        }
        else{
            last->next = temp;
            last = temp;
        }
    }
    // last->next = start->next->next;
    last->next = start;
    // last->next = NULL;
    return start;
}

int checkLoop(node *start) {
    node *fast, *slow;
    int count = 0;
    fast = slow = start;
    if(fast->next->next == NULL)
        return 0;
    while(fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        count++;
        if(fast == slow){
            return count;
        }
    }
    return 0;
}

int main () {
    node *start = createLoopll();
    int size = checkLoop(start);
    if(size){
        printf("Loop detected! ");
        printf("\nThe size of loop: %d\n", size);
    }
    else
    {
        printf("Loop not detected! ");
    }
    return 0;
}
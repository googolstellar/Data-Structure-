// Let p be a pointer to the first node in a singly linked list. Write a procedure to delete every
// other node beginning with p (i.e. the first, third, fifth, etc. node of the list are to be deleted).
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node * createll() {
    int val;
    node *start = NULL, *temp = NULL, *last = NULL;
    //creation of first node
    printf("Enter the elements (till -1 inputted): ");
    start = (node *)malloc(sizeof(node));
    scanf("%d", &val);
    start->data = val;
    start->next = NULL;
    last = start;
    //take input till -1 recieved    
    scanf("%d", &val);
    while(val != -1){
        temp = (node *)malloc(sizeof(node));
        temp->data = val;
        temp->next = NULL;
        last->next = temp;
        last = last->next;
        scanf("%d", &val);
    }
    last->next = NULL;
    return start;
} 

node * trimll(node **pstart) {
    node *temp = NULL, *t = NULL;
    temp = *pstart;
    *pstart = (*pstart)->next;
    t = *pstart;
    while(t != NULL && t->next != NULL){
        temp = t->next;
        t->next = t->next->next;
        t = t->next;
    }
    return *pstart;
}

void display(node *start) {
    node *t = start;
    if(t == NULL){
        printf("No Nodes to show!\n ");
        return;
    }
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    node *start = NULL, *last = NULL, *temp;
    start = createll();
    printf("The original linked list is: ");
    display(start);
    start = trimll(&start);
    printf("\nThe new linked list is: ");
    display(start);
    printf("\n");
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

#define END 9999
typedef struct node {
    int data;
    struct node *next;
} node;

//insert a node
void insertNode(node **pstart, int val, int pos){
    node *temp = NULL, *t = NULL;
    //dynamically allocating memory to temp
    temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    if(pos == 0){
        temp->next = *pstart;
        *pstart = temp;
    } 
    else if(pos == END){
        t = *pstart;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
    }
    else{
        t = *pstart;
        while(--pos){
            t = t->next;
        }
        temp->next = t->next;
        t->next = temp;
    }
    return ;
}

//delete a node
int deleteNode(node **pstart, int pos){
    node *temp = NULL, *t = NULL;
    if(pos == 0){
        if(*pstart != NULL) {
            temp = *pstart;
            *pstart = (*pstart)->next;
        }
        else{
            printf("No more nodes to delete! ");
            return END;
        }
    }
    else if(pos == END) {
        t = *pstart;
        if(t == NULL) {
            printf("No more nodes to delete! ");
            return END;
        }
        if(t->next == NULL) {
            temp = t;
            *pstart = NULL; 
            return temp->data;
        }
        while(t->next->next != NULL){
            t = t->next;
        }
        temp = t->next;
        t->next = NULL;
    }
    else {
        t = *pstart;
        if(t == NULL){
            printf("No more nodes to delete! ");
            return END;
        }
        while(--pos && t->next != NULL){
            t= t->next;
        }
        if(t->next == NULL){
            printf("Not Valid input! ");
            return END;
        }
        temp = t->next;
        t->next = t->next->next;
    }
    return temp->data;
}

void display(node **pstart) {
    node *t = *pstart;
    if(t == NULL) {
        printf("No more nodes to delete!\n");
    }
    while(t != NULL){
        printf("%d ", t->data);
        t = t->next;
    }
}

int main () {
    node *start = NULL;
    int choice, choice2, data, pos = 0;
    do{
        system("clear");
        printf("Linked list operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Display the linked list\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                   do{
                       system("clear");
                       printf("1. Insert at begining\n");
                       printf("2. Insert at end\n");
                       printf("3. Insert in between\n");
                       printf("4. Exit\n");
                       printf("Enter Your choice: ");
                       scanf("%d", &choice2);
                       switch(choice2){
                           case 1:
                                  pos = 0;   
                                  printf("Enter the number to be inserted: ");
                                  scanf("%d", &data); 
                                  insertNode(&start, data, pos);
                                  break;
                           case 2:
                                  pos = END;
                                  printf("Enter the number to be inserted: ");
                                  scanf("%d", &data);
                                  insertNode(&start, data, pos);
                                  break;
                            case 3:
                                   printf("Enter the number of elements after which You wanna insert: ");
                                   scanf("%d", &pos);
                                   printf("Enter the number to be inserted: ");
                                   scanf("%d", &data);
                                   insertNode(&start, data, pos);
                                   break;
                            case 4:
                                    break;
                            default: 
                                     printf("Invalid Entry!\n");
                                     break;
                       }
                   } 
                   while(choice2 <= 3);
                   break; 
            case 2:
                   do{
                       system("clear");
                       printf("1. Delete from begining\n");
                       printf("2. Delete from end\n");
                       printf("3. Delete from between\n");
                       printf("4. Exit\n");
                       printf("Enter Your choice: ");
                       scanf("%d", &choice2);
                       switch(choice2){
                           case 1:
                                  pos = 0;    
                                  data = deleteNode(&start, pos);
                                  if(data != END){
                                      printf("Deleted value is: %d\n", data);
                                  }
                                  getchar();
                                  getchar();
                                  break;
                           case 2:
                                  pos = END;
                                  data = deleteNode(&start, pos);                     
                                  if(data != END){
                                      printf("Deleted value is: %d\n", data);
                                  }
                                  getchar();
                                  getchar();
                                  break;
                            case 3:
                                   printf("Enter the number of elements after which You wanna delete: ");
                                   scanf("%d", &pos);
                                   data = deleteNode(&start, pos);
                                   if(data != END){
                                      printf("Deleted value is: %d\n", data);
                                   }
                                   getchar();
                                   getchar();
                                   break;
                            case 4: break;
                            default: 
                                     printf("Invalid Entry!\n");
                                     break;
                       }
                   } 
                   while(choice2 <= 3);
                   break; 
            case 3: 
                    display(&start);
                    getchar();
                    getchar();
                    break;
            case 4: break;
            default: printf("Invalid choice! ");
        }
    }
    while(choice <= 3);
    return 0;
}
#include<stdio.h>
#define MAX 100
int stack[MAX], top = -1;

int isStackEmpty(){
    
};
int isStackFull();
int push(int val);
int pop();

int main(){
    int choice, val, result;
    printf("Stack Operations");
    printf("\n1. Push an element in stack top");
    printf("\n2. Pop an element from stack top");
    printf("\n3. Check if stack is full");
    printf("\n4. Check if stack is empty");
    printf("\n5. Exit");
    printf("\nNow enter your choice: ");
    switch(choice){
        case 1:
                printf("Enter the value to be pushed :");
                scanf("%d", &val);
                result = push(val);
                if(result) 
                    printf("Element pushed successfully");
                else
                    printf("Push operation failed !");
                break;
        case 2:
                result = pop();
                if(result) 
                    printf("Element poped successfully");
                else
                    printf("Pop operation failed !");  
                break; 
        case 3:
                result = isStackFull();
                if(result)
                    printf("Stack is Full!");
                else
                    printf("Stack is not full");
                break;
        case 4:
                result = isStackEmpty();
                if(result)
                    printf("Stack is Empty!");
                else
                    printf("Stack is not empty");
                break;     
        case 5:
                break;  
        default:printf("Invalid choice !");        
    }
    while(choice < 5);
    return 0;
}
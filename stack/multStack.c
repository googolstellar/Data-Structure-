// Multiple stack in an array
//for now 2
#include<stdio.h>
#define MAX 100
int stack[MAX];
int top1 = -1, top2 = MAX;

int isStackFull(){
    if(top1+1 == top2)
        return 1;
    else 
        return 0;
}

int isStackEmpty1(){
    if(top1 <= -1)
        return 1;
    else
        return 0; 
}

int isStackEmpty2(){
    if(top1 >= MAX)
        return 1;
    else
        return 0; 
}

//push in stack1
void push1(int val){
    if(!isStackFull()){
        top1++;
        stack[top1] = val;
    }
    else{
        printf("Stack1 is FULL...");
    }
}

//push in stack2
void push2(int val){
    if(!isStackFull()){
        top2--;
        stack[top2] = val;
    }
    else{
        printf("Stack2 is FULL...");
    }
}

//pop stack1
int pop1(){
    if(!isStackEmpty1()){
        return stack[top1--];
    }
    else{
        printf("Stack1 is EMPTY...");
    }
}

//pop stack2
int pop2(){
    if(!isStackEmpty2()){
        return stack[top2++];
    }
    else{
        printf("Stack2 is EMPTY...");
    }
}

void display1(){
    int i; 
    int flag = 0;
    for(i = 0; i <= top1; i++){
        flag = 1;
        printf("%d ", stack[i]);
    }
    if(flag == 0){
        printf("Stack1 is Empty...");
    }
}

void display2(){
    int i; 
    int flag = 0;
    for(i = MAX-1; i >= top2; i--){
        flag = 1;
        printf("%d ", stack[i]);
    }
    if(flag == 0){
        printf("Stack2 is Empty...");
    }
}


int main(){
    int choice1, choice2, val;
    do{ 
        printf("\e[1;1H\e[2J");
        printf("\nStack Operations\n");
        printf("\nPress 3 to exit");
        printf("\nOn Which Stack do you wanna operate?(1/2) ");

        scanf("%d", &choice1);
        switch(choice1){
            case 1:{
                do{ 
                    printf("\e[1;1H\e[2J");
                    printf("\nStack1:");
                    printf("\n1. Push an element in stack1 top");
                    printf("\n2. Pop an element from stack1 top");
                    printf("\n3. Check if stack1 is full");
                    printf("\n4. Check if stack1 is empty");
                    printf("\n5. Display");
                    printf("\n6. Exit");
                    printf("\nNow enter your choice: ");
                    scanf("%d", &choice2);
                    switch(choice2){
                        case 1:
                                printf("Enter the value to be pushed :");
                                scanf("%d", &val);
                                push1(val);
                                break;
                        case 2:
                                val = pop1();
                                printf("Poped value is: %d", val);
                                getchar();
                                getchar();  
                                break; 
                        case 3:
                                if(isStackFull())
                                    printf("Stack is Full...");
                                else
                                    printf("Stack is not FULL...");
                                getchar();
                                getchar();  
                                break;
                        case 4:
                                if(isStackEmpty1())
                                    printf("Stack is EMPTY...");
                                else
                                    printf("Stack is not EMPTY...");
                                getchar();
                                getchar();  
                                break; 
                        case 5:
                                display1(); 
                                getchar();
                                getchar();  
                                break;
                        case 6: break;
                        default:printf("Invalid choice...");       
                    }           
                }
                while(choice2 <= 5);
                break;
            }
            case 2:{
                do{
                    printf("\e[1;1H\e[2J");
                    printf("Stack Operations");
                    printf("\n1. Push an element in stack2 top");
                    printf("\n2. Pop an element from stack2 top");
                    printf("\n3. Check if stack2 is full");
                    printf("\n4. Check if stack2 is empty");
                    printf("\n5. Display");
                    printf("\n6. Exit");
                    printf("\nNow enter your choice: ");
                    scanf("%d", &choice2);
                    switch(choice2){
                        case 1:
                                printf("Enter the value to be pushed :");
                                scanf("%d", &val);
                                push2(val);
                                break;
                        case 2:
                                val = pop2();
                                printf("Poped value is: %d", val);
                                getchar();
                                getchar();  
                                break; 
                        case 3:
                                if(isStackFull())
                                    printf("Stack is Full...");
                                else
                                    printf("Stack is not FULL...");
                                getchar();
                                getchar();  
                                break;
                        case 4:
                                if(isStackEmpty2())
                                    printf("Stack is EMPTY...");
                                else
                                    printf("Stack is not EMPTY...");
                                getchar();
                                getchar();  
                                break; 
                        case 5:
                                display2();
                                getchar();
                                getchar();  
                                break;
                        case 6: break;      
                    }       
                } 
                while(choice2 <= 5);  
            }
            default:("Invalid Choice...");
        } 
    }
    while(choice1 <= 2);
    return 0;
}

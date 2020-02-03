#include<stdio.h>
#define MAX 5
#define ERROR -99999
float stack[MAX];
int top = -1;

int isStackFull(){
    if(top >= MAX - 1)
        return 1;
    else 
        return 0;
}

int isStackEmpty(){
    if(top <= -1)
        return 1;
    else
        return 0;
}

int push(float val){
    if(isStackFull()){
        printf("The Stack is Full! ");
        return 0;
    }
    else{
        top++;
        stack[top] = val;
        return 0;
    }
}

int pop(){
    if(isStackEmpty()){
        printf("The Stack is Empty! ");
        return 0;
    }
    else{
        return stack[top--];
    }
}

float evalExpr(char expr[MAX]){
    int i = 0;
    float opr1, opr2, result;
    int status;
    while(expr[i] != '\0'){
        if(expr[i] >= '0' && expr[i] <= '9') //only valid for single digit operand
        {
            float num = expr[i] - '0';
            status = push(num);
            if(status == ERROR){
                printf("Some Error occurred!");
                return 0;
            }   
        }
        else{
            switch(expr[i]){
                case '+':
                        opr1 = pop();
                        opr2 = pop();
                        result = opr2 + opr1;
                        status = push(result);
                        if(status == ERROR){
                            printf("Some Error occurred!");
                            return 0;
                        }  
                        break;  
                case '-':
                        opr1 = pop();
                        opr2 = pop();
                        result = opr2 - opr1;
                        status = push(result);
                        if(status == ERROR){
                            printf("Some Error occurred!");
                            return 0;
                        }  
                        break;   
                case '*':
                        opr1 = pop();
                        opr2 = pop();
                        result = opr2 * opr1;
                        status = push(result);
                        if(status == ERROR){
                            printf("Some Error occurred!");
                            return 0;
                        }  
                        break;   
                case '/':
                        opr1 = pop();
                        opr2 = pop();
                        result = opr2 / opr1;
                        status = push(result);
                        if(status == ERROR){
                            printf("Some Error occurred!");
                            return 0;
                        }  
                        break;                                          
            }
        }
        i++;
    }
}

int main(){
    char expr[MAX];
    printf("Enter a valid postfix expression :");
    scanf("%s", expr);
    float result = evalExpr(expr);
    printf("%f\n", result);
}
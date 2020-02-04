#include<stdio.h>
#define MAX 100
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

void push(float val){
    if(isStackFull()){
        printf("The Stack is Full! ");
        return;
    }
    else{
        top++;
        stack[top] = val;
        return;
    }
}

int pop(){
    if(isStackEmpty()){
        printf("The Stack is Empty! ");
        return ERROR;
    }
    else{
        return stack[top--];
    }
}

float evalExpr(char expr[MAX]){
    int i = 0, j;
    float opr1, opr2, result, num = 0;
    int status;
    while(expr[i] != '\0'){
        if(expr[i] == ' ')
            i++;
        else{
            j = i;
            if(expr[j] >= '0' && expr[j] <= '9') 
            {   
                num = 0;
                while(expr[j] != ' '){
                    num = 10.0 * num + expr[j] - '0';  
                    j++;
                }
                i = j+1;
                push(num);
            }
            else{
                switch(expr[i]){
                    case '+':
                            opr2 = pop();
                            opr1 = pop();
                            result = opr1 + opr2;
                            push(result);
                            break;  
                    case '-':
                            opr2 = pop();
                            opr1 = pop();
                            result = opr1 - opr2;
                            push(result);
                            break;   
                    case '*':
                            opr2 = pop();
                            opr1 = pop();
                            result = opr1 * opr2;
                            push(result);
                            break; 
                    case '/':
                            opr2 = pop();
                            opr1 = pop();
                            result = opr1 / opr2;
                            push(result);
                            break;                                          
                }
                i++;
            } 
        }
    }
    return pop();  //working without return statement(because whatsoever left in register at last is returned in this case)
}

int main(){
    char expr[MAX];
    printf("Enter a valid postfix expression :");
    fgets (expr, 100, stdin);
    float res = evalExpr(expr);
    printf("%f\n", res);
}

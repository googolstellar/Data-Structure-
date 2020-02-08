#include<stdio.h>
#define MAX 100
#define ERROR '$'
char stack[MAX];
int top = 0;

typedef struct priority{
    int order;
    char oper;
}priority;

priority pri[] = { {0, '-'}, {0, '+'}, {1, '*'}, {1, '/'}, {3, '('} };

void push(char oper){
    if(top >= MAX - 1){
        printf("Stack is Full");
        return ;
    }
    else{
        top++;
        stack[top] = oper;
    }
}

char pop(){
    if(stack[top] != '$' && top > 0){
        return stack[top--];
    }
    else{
        return ERROR;
    }
}

int priorityCheck(char oper){
    int i = 0, operPri, stackPri;
    if(stack[top] != '$' && stack[top] != '('){
        while(i < 5){
            if(oper == pri[i].oper)
                operPri = pri[i].order;
            if(stack[top] == pri[i].oper)
                stackPri = pri[i].order;
            i++;
        }
        if(operPri > stackPri){
            return 1; //need to be pushed
        }
        else if(operPri <= stackPri){
            return 0; //need to be poped
        }
    }
    else if(stack[top] == '(' || stack[top] == '$'){
        return 1;
    }
    else{
        return ERROR;
    }
}

void infixToPostfix(char infix[MAX], char postfix[MAX]){
    int i = 0, j = 0;
    char popOper;
    while(infix[i] != '\0' && infix[i] != '\n'){
        if(infix[i] >= '0' && infix[i] <= '9'){
            postfix[j++] = infix[i++];
        }
        else{
            if(infix[i] == ')'){
                do{
                    popOper = pop();
                    if(popOper == ERROR)
                        return;
                    if(popOper != '('){
                        postfix[j++] = popOper;
                    }
                }
                while(popOper != '(');
                i++;
            }
            else{
                if(priorityCheck(infix[i]) == ERROR)
                    return;
                if(priorityCheck(infix[i]) == 1){
                    push(infix[i++]);
                }
                else if(priorityCheck(infix[i]) == 0){
                    popOper = pop();
                    if(popOper != ERROR){
                        postfix[j++] = popOper;
                        push(infix[i++]);
                    } 
                    else
                        return;  
                }
            } 
        }
    }
    while(stack[top] != '$'){
        popOper = pop();
        postfix[j++] = popOper;
    }
    postfix[j] = '\0';
}

int main(){
    char infix[MAX], postfix[MAX];
    int i = 0;
    stack[0] = '$';
    printf("Enter a valid infix expression : ");
    fgets(infix, MAX, stdin);
    infixToPostfix(infix, postfix);
    printf("Postfix notation for given infix notation is: ");
    printf("%s\n", postfix);
}

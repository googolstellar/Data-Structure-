#include<stdio.h>
#define MAX 100
#define ERROR '$'
char stack[MAX];
int top = -1;
typedef struct priority{
    int order;
    char oper;
}priority;

priority pri[] = { {0, '-'}, {0, '+'}, {2, '*'}, {2, '/'}, {3, '('} };

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
    if(stack[top] != '$'){
        return stack[top--];
    }
    else{
        printf("Stack is Empty");
        return ERROR;
    }
}

int priorityCheck(char oper){
    int i = 0, operPri, stackPri;
    if(stack[top] != '$'){
        while(i <= 4){
            if(oper == pri[i].oper)
                operPri = pri[i].order;
            else if(stack[top] == pri[i].oper)
                stackPri = pri[i].order;
            i++;
        }
        // if(i > 4){
        //     printf("Invalid operator!");
        //     return ERROR;
        // }
        if(operPri > stackPri){
            return 1; //need to be pushed
        }
        else if(operPri <= stackPri){
            return 0; //need to be poped
        }
    }
    else{
        return 1;
    }
}

void infixToPostfix(char infix[MAX], char postfix[MAX]){
    int i = 0, j = 0;
    char popOper;
    while(infix[i++] != '\0'){
        if(infix[i] >= '0' && infix[i] <= '9'){
            postfix[j++] = infix[i];
        }
        else{
            if(infix[i++] == ')'){
                do{
                    popOper = pop();
                    if(popOper == ERROR)
                        return;
                    if(popOper != '('){
                        postfix[j++] = popOper;
                    }
                }
                while(popOper != '(');
            }
            else if(priorityCheck(infix[i])){
                push(infix[i]);
            }
            else{
                popOper = pop();
                if(popOper != ERROR){
                    postfix[j++] = popOper;
                    push(infix[i]);
                } 
                else
                    return;  
            }
        }
    }
    postfix[j] = '\0';
    printf("**%d ", i);
}

int main(){
    char infix[MAX], postfix[MAX];
    int i = 0;
    stack[0] = '$';
    printf("Enter a valid infix expression : ");
    fgets(infix, MAX, stdin);
    infixToPostfix(infix, postfix);
    // while (postfix[i] != '\0')
    // {
    //     printf("%c", postfix[i++]);
    // }
    printf("$%s$\n", postfix);
    
}

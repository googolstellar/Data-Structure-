#include<stdio.h>
#define MAX 100
#define ERROR -10000
int queue[MAX];
int front = -1, rear = -1;

int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if(front == 0 && rear == MAX - 1)
        return 1;
    else
        return 0;
}

int qinsert(int val){
    if(isFull()){
        printf("Queue is full!");
        return ERROR;
    }
    if(front == -1){
        front++;
        rear++;
        queue[rear] = val;
    }
    else{
        rear++;
        queue[rear] = val;
    }
    return val;
}

int qdelete(){
    if(isEmpty()){
        printf("Queue is Empty!");
        return ERROR;
    }
    return queue[front++];
}

void display(){
    if(isEmpty()){
        printf("The queue is empty!");
        return;
    }
    int temp = front;
    while(temp <= rear){
        printf("%d ", queue[temp++]);
    }
}

int main(){
    int choice, val, result;
    char ch;
    do{
        printf("\e[1;1H\e[2J");   //regex method for clearing screen(very fast in comparison to system(clear))
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Check if queue is empty");
        printf("\n4. Check if queue is full");
        printf("\n5. Display the Queue");
        printf("\n6. Exit");
        printf("\nNow enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                    printf("Enter the value to be inserted : ");
                    scanf("%d", &val);
                    result = qinsert(val);
                    if(result != ERROR)
                        printf("%d inserted successfully ", result);
                    break;
            case 2: 
                    val = qdelete();
                    if(val != ERROR)
                        printf("The deleted value is : %d", val);
                    break;
            case 3:
                    if(isEmpty()){
                        printf("The queue is empty!");
                    }
                    else{
                        printf("The queue is not empty!");
                    }
                    break;
            case 4:
                    if(isFull()){
                        printf("The queue is Full!");
                    }
                    else{
                        printf("The queue is not full!");
                    }
                    break;
            case 5:
                    display();
            case 6:break;
            default: printf("Invalid choice");
        }
        getchar();
        printf("\nDo you wanna enter more(y/n) : ");
        scanf("%c", &ch);
    }
    while(ch == 'y' || ch == 'Y');
    return 0;
}
#include<stdio.h>
#define MAX 5
#define FULL -9999
#define EMPTY -9998
#define CONTINUE -9997
#define ERROR -9996
int queue[MAX];
int front = MAX - 2, rear = MAX - 2;

int isEmpty(){
    if(queue[MAX - 1] == EMPTY)
        return 1;
    else 
        return 0;
}

int isFull(){
    if(queue[MAX - 1] == FULL)
        return 1;
    else 
        return 0;
}

void insertQ(int val){
    //Check Status
    if(!isFull()){
        rear = (rear + 1) % (MAX-1);
        queue[rear] = val;
        //update Status
        if((rear) % (MAX-1) == front){
            queue[MAX-1] = FULL;
        }
        else{
            queue[MAX-1] = CONTINUE;
        }
        // printf("Status %d ", queue[MAX-1]);
    }
    else{
        printf("Queue is FULL...");
        getchar();
        getchar();
        return;
    }
}

int deleteQ(){
    //Check Status
    if(!isEmpty()){
        //Update Status
        front = (front + 1) % (MAX-1);
        if((front) % (MAX-1) == rear){
            queue[MAX-1] = EMPTY;
        }
        else{
            queue[MAX-1] = CONTINUE;
        }
        return queue[front];
    }
    else{
        printf("Queue is EMPTY...");
        return ERROR;
    }
}

void display(){
    int i = front;
    if(isEmpty()){
        printf("Queue is EMPTY...");
        return;
    }
    do{
        i = (i + 1) % (MAX - 1);
        printf("%d ", queue[i]);
    }
    while(i != rear);
}

int main(){
    int choice, val;
    queue[MAX-1] = EMPTY; //For Status 
    do{
        printf("\e[1;1H\e[2J");
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Check if queue is empty\n");
        printf("4.Check if queue is full\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                    printf("Enter the value to be inserted: ");
                    scanf("%d", &val);
                    insertQ(val);
                    break;
            case 2: 
                    val = deleteQ();
                    if(val != ERROR)
                        printf("Deleted Value: %d", val);
                    getchar();
                    getchar();//for actual input of user
                    break;
            case 3: 
                    if(isEmpty())
                        printf("Queue is EMPTY...");
                    else
                        printf("Queue is not EMPTY...");
                    getchar();
                    getchar();//for actual input of user
                    break;
            case 4: 
                    if(isFull())
                        printf("Queue is FULL...");
                    else
                        printf("Queue is not FULL...");
                    getchar();
                    getchar();//for actual input of user
                    break;
            case 5: 
                    display();
                    getchar();//for removing \n from the buffer
                    getchar();//for actual input of user
                    break;                    
        }
    }
    while(choice <= 6);
    return 0;
}
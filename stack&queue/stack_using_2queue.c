#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
typedef struct queue_using_array
{
    int capacity;
    int head;
    int tail;
    int* arr;
}queue;

queue* create_queue(int capacity)
{
    queue* Q=(queue*)malloc(sizeof(queue));
    Q->tail=-1;
    Q->head=-1;
    Q->arr=(int*)calloc(capacity,sizeof(int));
    return Q;
}
int enqueue(queue* Q,int input)
{   if(Q->tail>=(Q->capacity))
    {
        printf("the stack is full\n");
        return 0;
    }
    if(Q->head==-1)
    {
        Q->head=0;   
    }
    Q->tail+=1;
    Q->arr[Q->tail]=input;
    return Q->arr[Q->tail];
}
int dequeue(queue* Q)
{
    if(Q->head>Q->tail || Q->tail==-1)
    {
        printf("The stack is empty");
    }
    else{
        int remove=Q->arr[Q->head];
        Q->head++;
        return remove;
    }
}
void peek(queue* Q)
{
    printf("the element at top of stack is %d\n",Q->arr[Q->head]);
}
bool isEmpty(queue* Q)
{
    if(Q->head==-1 || Q->tail==-1|| Q->head>Q->tail)
    {
        return true;
    }
    return false;
}
void size(queue* Q)
{
    printf("the size of stack is  %d\n",(Q->tail-Q->head)+1);
}
void push(queue* q1, queue* q2,int input)
{
    while (!isEmpty(q1))
    {
        enqueue(q2,dequeue(q1));
    }
    enqueue(q1,input);
    printf("added %d to top of stack\n",input);
    while(!isEmpty(q2))
    {
        enqueue(q1,dequeue(q2));
    }
}

int main()
{   int capacity;
    int input;
    printf("Enter the maximum capaity of the stack\n");
    scanf("%d",&capacity);
    queue* q1=create_queue(capacity);
    queue* q2=create_queue(capacity);
    printf("choose actions to perform on stack\n\
    1-push\n\
    2-pop\n\
    3-peek\n\
    4-isEmpty\n\
    5-size\n\
    6-exit");
    while(1)
    {
    int choice;
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 1:
        scanf("%d",&input);
        push(q1,q2,input);;
        break;
    case 2:
        dequeue(q1);
        break;
    case 3:
        peek(q1);
        break;
    case 4:
        if(isEmpty(q1))
        {
            printf("stack is empty");
        }
        else{
            printf("stack is not empty");
        }
        break;
    case 5:
        size(q1);
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("invalid input\n");
        break;
    }
}
    return 0;
}
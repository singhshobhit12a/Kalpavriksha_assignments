#include<stdlib.h>
#include<stdio.h>
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
void enqueue(queue* Q)
{   if(Q->tail>=(Q->capacity))
    {
        printf("the queue is full\n");
        return ;
    }
    int input;
    scanf("%d",&input);
    if(Q->head==-1)
    {
        Q->head=0;   
    }
    Q->tail+=1;
    Q->arr[Q->tail]=input;
    printf("added %d to queue\n",Q->arr[Q->tail]);
}
void dequeue(queue* Q)
{
    if(Q->head>Q->tail || Q->tail==-1)
    {
        printf("The queue is empty");
    }
    else{
        printf("removing %d",Q->arr[Q->head]);
        Q->head++;
    }
}
void peek(queue* Q)
{
    printf("the element at head of queue is %d\n",Q->arr[Q->head]);
}
void isEmpty(queue* Q)
{
    if(Q->head>Q->tail)
    {
        printf("The queue is empty\n");
    }
    else{
        printf("queue is not is not empty\n");
    }
}
void size(queue* Q)
{
    printf("the size of queue id %d\n",(Q->tail-Q->head)+1);
}

int main()
{
    int capacity;
    printf("enter the max_capacity of queue\n");
    scanf("%d",&capacity);
    queue* Q=create_queue(capacity);
    printf("choose actions to perform on stack\n\
    1-enqueue\n\
    2-dequeue\n\
    3-peek\n\
    4-isEmpty\n\
    5-size\n\
    6-exit\n");
    while(1)
    {
    int choice;
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 1:
        enqueue(Q);
        break;
    case 2:
        dequeue(Q);
        break;
    case 3:
        peek(Q);
        break;
    case 4:
        isEmpty(Q);
        break;
    case 5:
        size(Q);
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
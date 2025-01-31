#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int top;
    int capacity;
    int* arr;
}stack;

stack* create_stack(int capacity)
{
    stack* stk=(stack*)malloc(sizeof(stack));
    stk->top=-1;
    stk->arr=(int*)malloc(capacity*sizeof(int));
    return stk;
}
stack* initialize(int capacity)
{
    stack* stk=(stack*)malloc(sizeof(stack));
    stk->capacity=capacity;
    stk->arr=(int* )malloc(capacity*sizeof(int));
    stk->top=-1;
    return stk;
}
bool isEmpty(stack* stk)
{
    if(stk->top==-1)
    {
        return true;
    }
    return false;    
}

int enqueue(stack* stk,int input)
{
    if(stk->top>=(stk->capacity-1))
    {
        printf("the queue is full");
        return __INT_MAX__;
    }
    stk->arr[++stk->top]=input;
    return input;
}
int pop(stack* stk)
{
    if(stk->top==-1)
    {
        printf("queue is empty\n");
        return 0 ;
    }
    int removed=(stk->arr[stk->top]);
    stk->top--;
    return removed;
}
void dequeue(stack* stk)
{   
    if(stk->top==-1)
    {
        printf("the queue is empty");
    }
    if(stk->top==0)
    {
        printf("removed from queue %d",pop(stk));
        return;
    }
    else{
        int remove=stk->arr[stk->top];
        stk->top--;
        dequeue(stk);
        enqueue(stk,remove);
    }
}
void peek(stack* stk)
{
    if(stk->top==0)
    {
        printf("%d is at head of the queue",stk->arr[stk->top]);
        return;
    }
    else{
        int remove=stk->arr[stk->top];
        stk->top--;
        peek(stk);
        stk->top++;
    }
}

int size(stack* stk)
{
   return (stk->top)+1;
}

int main()
{   int capacity;
    printf("enter the capacity of the queue");
    scanf("%d",&capacity);
    stack* s1=initialize(capacity);
    int input;
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
        scanf("%d",&input);
        int added=enqueue(s1,input);
        if(added!=__INT_MAX__)
        {printf("added %d to queue\n",added);}
        break;
    case 2:
        dequeue(s1);
        break;
    case 3:
        peek(s1);
        break;
    case 4:
        if(isEmpty(s1))
        {
            printf("queue is empty\n");
        }
        else{
            printf("queue is not empty\n");
        }
        break;
    case 5:
        size(s1);
        break;
    case 6:
        exit(0);
        break;
    default:
       printf("invalid input\n");
    }
    }
    return 0;
}
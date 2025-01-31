#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct stack{
    int top;
    int capacity;
    int* arr;
}stack;

bool isEmpty(stack* stk)
{
    if(stk->top==-1)
    {
        return true;
    }
    return false;    
}
int pop(stack* stk)
{
    int removed=(stk->arr[stk->top]);
    stk->top--;
    return removed;
}
stack* create_stack(int capacity)
{
    stack* stk=(stack*)malloc(sizeof(stack));
    stk->top=-1;
    stk->arr=(int*)malloc(capacity*sizeof(int));
    return stk;
}

void enqueue(stack* stk,int input)
{
    stk->arr[++stk->top]=input;
    printf("added %d to stack\n",stk->arr[stk->top]);
}
void dequeue(stack* s1, stack* s2)
{
    while(!isEmpty(s1))
    {
        enqueue(s2,pop(s1));
    }
    printf("%d",s2);
    while(!isEmpty(s2))
    {
        enqueue(s1,pop(s2));
    }
}

void peek(stack* s1, stack* s2)
{
    while(!isEmpty(s1))
    {
        enqueue(s2,pop(s1));
    }
    printf("%d",s2->arr[s2->top]);
    while(!isEmpty(s2))
    {
        enqueue(s1,pop(s2));
    }
}

void size(stack* stk)
{
    printf("size of stack is %d\n",(stk->top)+1);
}
stack* initialize(int capacity)
{
    stack* stk=(stack*)malloc(sizeof(stack));
    stk->capacity=capacity;
    stk->arr=(int* )malloc(capacity*sizeof(int));
    stk->top=-1;
    return stk;
}
int main()
{   int capacity;
    printf("enter the capacity of the queue");
    scanf("%d",&capacity);
    stack* s1=initialize(capacity);
    stack* s2=initialize(capacity);
    int input;
    printf("choose actions to perform on stack\n\
    1-enqueue\n\
    2-dequeue\n\
    3-peek\n\
    4-isEmpty\n\
    5-size\n\
    6-exit(0)");
    while(1)
    {
    int choice;
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 1:
        scanf("%d",&input);;
        enqueue(s1,input);
        break;
    case 2:
        dequeue(s1,s2);
        break;
    case 3:
        peek(s1,s2);
        break;
    case 4:
        if(isEmpty(s1))
        {
            printf("queue is empty\n");
        }
        else{
            printf("queue is not empty");
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
       break;
    }
    return 0;
}
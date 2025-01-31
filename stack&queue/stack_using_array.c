#include<stdio.h>
#include<stdlib.h>

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
void push(stack* stk)
{
    int input;
    scanf("%d",&input);
    stk->arr[++stk->top]=input;
    printf("added %d to stack\n",stk->arr[stk->top]);
}
void pop(stack* stk)
{
    int removed=(stk->arr[stk->top]);
    stk->top--;
    printf("poped %d from stack\n",removed);
}
void peek(stack* stk)
{
    printf("top element is %d\n",stk->arr[stk->top]);
}
void isEmpty(stack* stk)
{
    if(stk->top==-1)
    {
        printf("stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
    }
}
void size(stack* stk)
{
    printf("size of stack is %d\n",(stk->top)+1);
}
int main()
{   int capacity;
    printf("Enter the maximum capaity of the stack\n");
    scanf("%d",&capacity);
    stack* stk=create_stack(capacity);

    printf("choose actions to perform on stack\n\
    1-push\n\
    2-pop\n\
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
        push(stk);
        break;
    case 2:
        pop(stk);
        break;
    case 3:
        peek(stk);
        break;
    case 4:
        isEmpty(stk);
        break;
    case 5:
        size(stk);
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
//implement queue using stack;
#include<stdio.h>
#include<stdlib.h>

int stack[100];
void push(int* top, int data)
{
    stack[++(*top)]=data;
}
void pop(int* top)
{
    if(*top==-1)
    {
        printf("None");
        return;
    }
    if(*top==0)
    {
        printf("%d",stack[*top]);
        *top=*top-1;
        return;
    }
    int saved=stack[*top];
    *top=*top-1;
    pop(top);
    push(top,saved);
}
void peek(int* top)
{
    if(*top==-1)
    {
        printf("None");
        return;
    }
    if(*top==0)
    {
        printf("%d",stack[*top]);
        return;
    }
    int saved=stack[*top];
    *top=*top-1;
    pop(top);
    push(top,saved);
}
void isempty(int* top)
{
    if(*top==-1)
    {
        printf("true");
    }
    else{
        printf("false");
    }
}
void size(int* top)
{
    printf("%d",*top);
}
int main()
{
    int top=-1;
    int num;
    int data;
    scanf("%d",&num);
    {
        while(num>0)
        {
            int choice;
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                scanf("%d",&data);
                push(&top, data);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(&top);
                break;
            case 4:
                isempty(&top);
                break;
            case 5:
                size(&top);
                break;
            
            default:
                break;
            }
            num--;
        }
    }
    return 0;
}
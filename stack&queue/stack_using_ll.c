#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void push(node** head)
{   int input;
    scanf("%d",&input);
    node* temp=(node*)malloc(sizeof(node));
    temp->data=input;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else{
        temp->next=*head;
        *head=temp;
    }
    printf("added the %d in stack\n",(*head)->data);
}
void pop(node** head)
{
    if(*head==NULL)
    {
        printf("stack is empty\n");
        return;
    }
    
   if((*head)->next!=NULL)
   {
    node* temp=(*head)->next;
    printf("poped %d from stack\n",(*head)->data);
    free(*head);
    *head=temp;
   }
   else{
    printf("poped %d from stack\n",(*head)->data);
    free(*head);
    *head=NULL;
   }
}
void peek(node** head)
{
    if(*head==NULL)
    {
       printf("stack is empty");
    }
     printf("element at top of stack is %d\n",(*head)->data);
}
void isEmpty(node** head)
{
    if(*head== NULL)
    {
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
}
void size(node** head)
{
    node*temp =*head;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    printf("Size of stack is %d\n",count);
}
int main()
{   node* head=NULL;
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
        push(&head);
        break;
    case 2:
        pop(&head);
        break;
    case 3:
        peek(&head);
        break;
    case 4:
        isEmpty(&head);
        break;
    case 5:
        size(&head);
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
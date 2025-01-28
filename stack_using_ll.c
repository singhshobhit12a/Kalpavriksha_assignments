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
void top(node** head)
{
    if(*head==NULL)
    {
       printf("stack is empty");
    }
     printf("element at top of stack is %d\n",(*head)->data);
}
int main()
{   node* head=NULL;
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
        top(&head);
        break;
    default:
       exit(0);
    }
}
    return 0;
}
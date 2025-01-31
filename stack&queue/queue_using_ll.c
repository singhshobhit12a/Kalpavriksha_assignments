#include<stdio.h>
#include<stdlib.h>

typedef struct queue_using_ll
{
    struct queue_using_ll* next;
    int data;
}queue;

void enqueue(queue** head, queue** tail)
{
    queue* temp=(queue*)malloc(sizeof(queue));
    int input;
    scanf("%d",&input);
    temp->data=input;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
    }
    else{
        (*tail)->next=temp;
    }
    *tail=temp;
    printf("added %d in the queue\n", (*tail)->data);
}
void dequeue(queue** head, queue** tail)
{   
    if(*head==NULL)
    {
        printf("the queue is empty\n");
    }
    else if(*head==*tail)
    {   
        printf("removed element %d from queue\n", (*head)->data);
        free(*head);
        *head=NULL;
        *tail=NULL;
    }
    else{
        queue* temp=*head;
        *head=(*head)->next;
        printf("removed element %d from queue\n", temp->data);
        free(temp);
    }
}
void peek(queue** head)
{
    printf("the element at head of queue is %d\n", (*head)->data);
}
void isEmpty(queue** head, queue** tail)
{
    if(*head==NULL && *tail==NULL)
    {
        printf("queue is empty\n");
    }
    else{
        printf("queue is not empty.\n");
    }
}
void size(queue** head)
{
    queue* temp=*head;
    int count=0;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    printf("the queue is of %d size\n",count);
}
int main()
{   queue* head=NULL;
    queue* tail=NULL;
    printf("choose actions to perform on stack\n\
    1-enqueue\n\
    2-dequeue\n\
    3-peek\n\
    4-isEmpty\n\
    5-size\n");
    while(1)
    {
    int choice;
    scanf("%d",&choice);
   
    switch (choice)
    {
    case 1:
        enqueue(&head,&tail);
        break;
    case 2:
        dequeue(&head,&tail);
        break;
    case 3:
        peek(&head);
        break;
    case 4:
        isEmpty(&head,&tail);
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
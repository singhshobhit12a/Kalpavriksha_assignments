#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int stack[100];
typedef struct node
{
   int data;
   struct node* next;
}node;

void fill_list(node** head, node** rear)
{
    int input;
    while (scanf("%d",&input)==1)
    {
        node* temp=(node*)calloc(1,sizeof(node));
        temp->data=input;
        temp->next=NULL;
        if(*head==NULL)
        {
            *head=temp;
            *rear=temp;
        }
        else{
            (*rear)->next=temp;
            *rear=temp;
        }
        char ch=getchar();
        if(ch=='\n')
        {
            break;
        }
    }
}
void enqueue(node** head, node** rear, int data)
{
    node* temp=(node*)calloc(1,sizeof(node));
    temp->data=data;
    temp->next=NULL;
    if(*head== NULL)
    {
        *head=temp;
        *rear=temp;
    }
    else{
        (*rear)->next=temp;
        *rear=temp;
    }
}
int dequeue(node** head, node** rear)
{
    if(*head==NULL)
    {
        printf("underflow");
        return -1; 
    }
    int data=(*head)->data;
    node* delete=*head;
    if(*head==*rear)
    {
        *head=NULL;
        *rear=NULL;
    }
    else{
        *head=(*head)->next;
    }
    free(delete);
    return data;
}
bool isEmpty(node** head)
{
    return *head==NULL;
}
void print_reverse(node** head)
{
    node* temp=*head;
    while(temp)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}
void reverse(node** head, node** rear, int k)
{
    node* temp_head=NULL;
    node* temp_rear=NULL;
    int top=-1;
    for(int i=0;i<k && !isEmpty(head);i++)
    {
        stack[++top]=dequeue(head, rear);
    }
    while(top>-1)
    {
        enqueue(&temp_head, &temp_rear,stack[top--]);
    }
    while(!isEmpty(head))
    {
        enqueue(&temp_head, &temp_rear, dequeue(head,rear));
    }
    print_reverse(&temp_head);
}
int main()
{
    node* head=NULL;
    node* rear=NULL;
    fill_list(&head, &rear);
    // while(head)
    // {
    //     printf("%d", head->data);
    //     head=head->next;
    // }
    int k;
    printf("enter the value of k");
    scanf("%d",&k);
    reverse(&head, &rear,k);
    return 0;
}
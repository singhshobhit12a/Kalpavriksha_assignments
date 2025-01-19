#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;
void add_starting(node** head,int* count)
{   int input;
    scanf("%d",&input);
    if(*head==NULL)
    {
        *head=(node*)malloc(sizeof(node));
        (*head)->data=input;
        (*head)->next=NULL;
        (*count)++;
        return;
    }
    node* new=(node*)malloc(sizeof(node));
    
    new->data=input;
    new->next=*head;
    *head=new;
    (*count)++;
    return;
}
void add_end(node** head,int* count)
{   
    if(*head==NULL)
    {
        add_starting(head,count);
    }

    node* current=*head;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    int input;
    scanf("%d",&input);
    node* temp=(node*)malloc(sizeof(node));
    temp->data=input;
    temp->next=NULL;
    current->next=temp;
    (*count)++;
}
void add_pos(node** head,int* count)
{   int pos;
    scanf("%d",&pos);
    if(pos<=0 || pos>(*count)+1){
        printf("invalid");
        exit(0);
    }
    else if(pos==1)
    {
        add_starting(head,count);
        return;
    }
    else if(pos==(*count)+1)
    {
        add_end(head,count);
        return;
    }
   
    int cur_count=1;

    node* prev=*head;
    while(cur_count<pos-1)
    {   prev=prev->next;
        cur_count++;
    }
    node* temp=(node*)malloc(sizeof(node));
    int input;
    scanf("%d",&input);
    temp->data=input;
    temp->next=prev->next;
    prev->next=temp;
    (*count)++;
}
void display(node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}
void update(node** head,int* count)
{
    int pos;
    scanf("%d",&pos);
    if(pos<=0 || pos>(*count)){
    printf("invalid");
    exit(0);
    }
    int cur_count=1;
    node* temp=*head;
    while(cur_count<pos && temp!=NULL)
    {
        temp=temp->next;
        cur_count++;
    }
    scanf("%d",&temp->data);
}
void delete_start(node** head,int* count)
{   if(*head==NULL)
    {
        printf("invalid");
        exit(0);
    }
    node* temp=*head;
    *head=(*head)->next;
    free(temp);
    (*count)--;
}
void delete_end(node** head,int* count)
{   
    if (*head == NULL) {
    printf("invalid");
    exit(0);
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        (*count)--;
        return;
    }
    node* temp=*head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* prev=temp;
    temp=temp->next;
    free(temp);
    prev->next=NULL;
    (*count)--;
}
void delete_pos(node** head,int* count)
{
    int pos;
    scanf("%d",&pos);
    if(pos<=0 || pos>*count)
    {
        printf("invalid");
        exit(0);
    }
    if(pos==1)
    {
        delete_start(head,count);
        return;
    }
    else if(pos==*count)
    {
        delete_end(head,count);
        return;
    }
    int cur_count=1;
    node* current=*head;
    while(cur_count<pos-1)
    {
        current=current->next;
        cur_count++;
    }
    node* temp=current->next;
    current->next=current->next->next;
    free(temp);
    (*count)--;
}
int main()
{   int num_op;
    scanf("%d",&num_op);
    int count=0;
    node* head=NULL;
    while (num_op>0)
   {
    int choose;
    scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            //create list
            add_end(&head,&count);
            break;
        case 2:
            //create list
            add_starting(&head,&count);
            break;
        case 3:
            //create list
            add_pos(&head,&count);
            break;
        case 4:
            //create list
            display(&head);
            break;
        case 5:
            //create list
            update(&head,&count);
            break;
        case 6:
            //create list
            delete_start(&head,&count);
            break;
        case 7:
            //create list
            delete_end(&head,&count);
            break;
        case 8:
            //create list
            delete_pos(&head,&count);
            break;
        default:
            printf("invalid..");
            exit(0);
            break;
        }
        num_op--;
   }

    return 0;
}

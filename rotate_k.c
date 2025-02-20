#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;

}node;
void fill_matrix(node** head,node** prev,int* count)
{   int input;
    
    while(scanf("%d",&input)==1)
    {
        node* temp=(node*)malloc(sizeof(node));
        temp->data=input;
        temp->next=NULL;
        if(*head==NULL)
        {
            *head=temp;
            
        }
        else{
            (*prev)->next=temp;
        }
        *prev=temp;
        char ch=getchar();
        if(ch=='\n')
        {
            return;
        }
        (*count)++;
    }
}
void rotate(node** head, int* count, int k)
{
    if(k>=*count){k=k%(*count);}
    for(int i=0;i<k;i++)
    {   node*prev=*head;
        while(prev->next->next!=NULL)
        {
            prev=prev->next;
        }

        (prev)->next->next=*head;
        *head=prev->next;
        prev->next=NULL;
        
    }
}
int main()
{   node* head=NULL;
    node*prev=head;
    int count=1;
    fill_matrix(&head,&prev,&count);
    // node*temp=head;
    // while(temp!=NULL)
    // {
    //     printf("%d",temp->data);
    //     temp=temp->next;
    // }
    int k;
    scanf("%d",&k);
    rotate(&head,&count, k);
    node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

int main()
 {  
    int input=0;
    node* head=(node*)calloc(1,sizeof(node));
    node* last=head;

    scanf("%d",&input);
    head->data=input;
    head->next=NULL;

    while (input!=-1)
    {   
        scanf("%d",&input);
        if(input==-1) break;
        node* cur=(node*)malloc(sizeof(node));
        cur->data=input;
        cur->next=NULL;
        last->next=cur;
        last=cur;
    }
    node* temp=head;
    while(temp!=NULL)
    {  
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("%d",slow->data);
    return 0;
}

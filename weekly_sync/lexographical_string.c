#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char* string;
    struct node* next;
}node;
void take_input(char* input)
{
    scanf("%[^\n]",input);
}
void create_linklist(node** head, char* input)
{   node* prev=*head;
    while(*input!='\0')
    {   
        node* temp_node=(node*)malloc(sizeof(node));
        temp_node->string=(char*)malloc(100*sizeof(char));
        char* str_ptr=temp_node->string;
        temp_node->next=NULL;
        while(*input!=' ' && *input!='\0')
        {
            *str_ptr++=*input++;
        }
        *str_ptr='\0';
        if(*head==NULL)
        {
            *head=temp_node;
        }
        else{
            prev->next=temp_node;
        }
        prev=temp_node;
        while(*input==' ')
        {
            input++;
        }
    }

}
void swap(char** str1, char** str2)
{
    char* temp=*str1;
    *str1=*str2;
    *str2=temp;
}
int str_cmp(char* str1, char* str2)
{
    char* ptr1=str1;
    char* ptr2=str2;
    while(*ptr1!='\0' && *ptr2!='\0')
    {
        if(*ptr1>*ptr2)
        {
            return 1;
        }
        else if(*ptr1<*ptr2)
        {
            return -1;
        }
        *ptr1++;
        *ptr2++;
    }
    if(*ptr1!='\0')
    {
        return 1;
    }
    if(*ptr2!='\0')
    {
        return -1;
    }
    return 0;
}
void sort_linklist(node** head)
{
    for(node* curr=*head;curr->next!=NULL;curr=curr->next)
    {
        for(node* next_curr=curr->next; next_curr!=NULL;next_curr=next_curr->next)
        {
            if(str_cmp(curr->string,next_curr->string)==1)
            {
                swap(&curr->string,&next_curr->string);
            }
        }
    }
}
int main()
{
    char* input=(char*)malloc(100*sizeof(char));
    take_input(input);
    node* head=NULL;
    create_linklist(&head,input);
    sort_linklist(&head);
    node* temp=head;
    while(temp)
    {
        printf("%s ",temp->string);
        temp=temp->next;
    }
    return 0;
}
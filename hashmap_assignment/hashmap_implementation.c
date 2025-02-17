#include<stdio.h>
#include<stdlib.h>
# define table_Size 10
typedef struct node{
    int key;
    int value;
    struct node* next;
}node;
int find_hash(int key)
{
    int hash;
    hash=key%table_Size;
    return hash;
}
void insert(node** arr)
{
    int key;
    int value;

    printf("Enter the key: ");
    scanf("%d",&key);

    printf("Enter the value: ");
    scanf("%d",&value);

    int hash=find_hash(key);
    node* temp=(node*)malloc(sizeof(node));
    temp->key=key;
    temp->value=value;
    temp->next=NULL;
    if((arr[hash])==NULL)
    {
        arr[hash]=temp;
    }
    else{
        node* itr=arr[hash];
        while (itr->next!=NULL)
        {
           if(itr->key==key)
           {
                itr->value=value;
                return;
           }
            itr=itr->next;
        }
        itr->next=temp;
    }
}
void search (node** arr)
{
    int key;
    int value;

    printf("Enter the key: ");
    scanf("%d",&key);

    int hash=find_hash(key);

    if(arr[hash]==NULL)
    {
        printf("Not found");
    }
    else{
        node* itr=arr[hash];
        while(itr!=NULL && itr->key!=key)
        {
            itr=itr->next;
        }
        if(itr==NULL)
        {
            printf("Not found");
            return;
        }
        printf("Value: %d",itr->value);
    }
}
void delete(node** arr)
{
    int key;
    int value;

    printf("Enter the key: ");
    scanf("%d",&key);

    int hash=find_hash(key);

    if(arr[hash]==NULL)
    {
        printf("this key do not exist");
    }
    else{
        node* itr=arr[hash];
        while(itr!=NULL && itr->next->key!=key)
        {
            itr=itr->next;
        }
        if(itr==NULL)
        {
            printf("this key do not exist");
        }
        node* temp=itr->next;
        itr->next=temp->next;
        free(temp);
        printf("Key %d deleted ",key);
    }
}
void display(node** arr)
{
    for(int i=0;i<table_Size;i++)
    {
        if(arr[i]!=NULL)
        {   node* itr=arr[i];
            printf("Index %d: ",i);
            while(itr!=NULL)
            {
                printf("(key=%d ,value=%d) ",itr->key,itr->value);
                itr=itr->next;
            }
            printf("\n");
        }
    }
}
int main()
{
    node** arr=(node**)calloc(10,sizeof(node*));
    int choice;
    printf("1- insert\n\
2-search\n\
3-delete\n\
4-display\n\
5-exit\n");
    while(1)
    {
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert(arr);
            break;
        
        case 2:
            search(arr);
            break;
        
        case 3:
            delete(arr);
            break;
        case 4:
            display(arr);
            break;
        
        case 5:
            exit(0);
        
        default:
            printf("enter right choice\n");
            break;
        }
    }
    return 0;
}
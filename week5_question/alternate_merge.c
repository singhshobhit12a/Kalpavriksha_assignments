#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;
void sort_linklist(node** head)
{
    for(node* curr=*head ;curr!=NULL;curr=curr->next)
    {
        for(node* next=curr->next;next!=NULL;next=next->next)
        {
            if(curr->data>next->data)
            {
                int temp=curr->data;
                curr->data=next->data;
                next->data=temp;
            }
        }
    }
}
void create_list(node** head) {
    node* prev = *head;
    int input;
    while (scanf("%d", &input) == 1) {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = input;
        temp->next = NULL;
        if (*head == NULL) {
            *head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        char ch = getchar();
        if (ch == '\n') {
            break;
        }
    }
}
node* find_mid(node** head)
{
    node* slow=*head;
    node* fast=(*head)->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void reverse(node** head)
{
    node* prev=NULL;
    node* curr=*head;
    node* next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}
void merge_linklist(node** head, node** next_head) {
    node* temp_first_list = *head;
    node* temp_sec_list = *next_head;
    node* temp_first_next;
    node* temp_sec_next;

    while (temp_first_list != NULL && temp_sec_list != NULL) {
        temp_first_next = temp_first_list->next;
        temp_sec_next = temp_sec_list->next;

        temp_first_list->next = temp_sec_list;
        if (temp_first_next == NULL) {
            break;
        }
        temp_sec_list->next = temp_first_next;

        temp_first_list = temp_first_next;
        temp_sec_list = temp_sec_next;
    }
}

void print_linklist(node** head)
{
    node* temp=*head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    node* head=NULL;
    create_list(&head);

    sort_linklist(&head);

    node* mid=find_mid(&head);

    node* next_head=mid->next;
    mid->next=NULL;
    printf("first half sorted linklist\n");
    print_linklist(&head);
    reverse(&next_head);
    printf("second half reversed sorted linklist\n");
    print_linklist(&next_head);
    merge_linklist(&head, &next_head);

    print_linklist(&head);
    return 0;
}
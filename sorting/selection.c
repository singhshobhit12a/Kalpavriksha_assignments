#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void make_list(node** head) {
    int input;
    node* prev = *head;
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

void selection_sort(node** head)
{
    for(node* curr=*head; curr!=NULL; curr=curr->next)
    {
        for(node* next =curr->next; next!=NULL; next=next->next)
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
int main()
{
    node* head=NULL;
    make_list(&head);
    node* temp=head;
    printf("Unsorted list is: ");
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    selection_sort(&head);
    temp=head;
    printf("Sorted list is: ");
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}
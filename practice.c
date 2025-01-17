#include<stdio.h>
#include<stdlib.h>
int is_digit(char *input)
{
    return *input>='0' && *input<='9';
}

typedef struct node{
    int data;
    struct node* next;
}node;

int main()
 {  
    char* input=(char*)malloc(100*sizeof(char));
    scanf("%[^\n]",input);

    node* head=(node*)malloc(sizeof(node));
    node* last=head;

    int first=1;

    while(*input!='\0')
    {   int temp=0;
        while(!is_digit(input) && *input!='\0')
        {
            input++;
        }
        while(*input!=' ' && is_digit(input))
        {
            temp=temp*10+*input-'0';
            input++;
        }
        if(first==1){
            head->data=temp;
            head->next=NULL;
            first=0;
        }
       else{
            node* cur=(node*)malloc(sizeof(node));
            cur->data=temp;
            cur->next=NULL;
            last->next=cur;
            last=cur;
       }
       input++;
    }

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

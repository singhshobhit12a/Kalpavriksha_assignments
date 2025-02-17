//create the linklist with the node storing 2 things, time complexity and space complexity.
//sort the linklist on the bases of timecomplexity and if the time complexity of two nodes
//are same then sort them on the bases of space complexity.
// 1 < logn < n < nlogn < n^2 < 2^n < n!
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef enum complexity{
    ONE,
    LOG_N,
    N,
    N_LOGN,
    N_SQR,
    TWO_POW_N,
    N_FACT,
}complexity;
typedef struct node
{
    complexity timeComplexity;
    complexity spaceComplexity;
    struct node* next;
}node;
complexity check_complexity(char* input)
{
    if(strcmp(input,"1")==0)
    {
        return ONE;
    }
     if(strcmp(input,"logn")==0)
    {
        return LOG_N;
    }
     if(strcmp(input,"n")==0)
    {
        return N;
    }
     if(strcmp(input,"nlogn")==0)
    {
        return N_LOGN;
    }
    if(strcmp(input,"n^2")==0)
    {
        return N_SQR;
    }
    if(strcmp(input,"2^n")==0)
    {
        return TWO_POW_N;
    }
    if(strcmp(input,"n!")==0)
    {
        return N_FACT;
    }
}
char* mapFromComplexity(complexity c)
{
    
    if(c==LOG_N)
    {
        return"logn";
    }
     if(c==N)
    {
        return "n";
    }
     if(c==N_LOGN)
    {
        return "nlogn";
    }
    if(c==N_SQR)
    {
        return "n^2";
    }
    if(c==TWO_POW_N)
    {
        return "2^n";
    }
    if(c==N_FACT)
    {
        return "n!";
    }
    if(c==ONE)
    {
        return "1";
    }
}
void getinput(node** head)
{
    int num;
    scanf("%d",&num);
    node* rear=*head;
    while(num>0)
    {

        char* time_complexity=(char*)malloc(100*sizeof(char));
        char* space_complexity=(char*)malloc(100*sizeof(char));
        scanf("%s",time_complexity);
        scanf("%s",space_complexity);
        complexity T= check_complexity(time_complexity);
        complexity S= check_complexity(space_complexity);
        node* temp=(node*)malloc(sizeof(node));
        temp->spaceComplexity=S;
        temp->timeComplexity=T;
        temp->next=NULL;
        if(*head==NULL)
        {
            *head=temp;
        }
        else{
            rear->next=temp;
        }
        rear=temp;
        num--;
    }
}
void sort(node** head)
{
    for(node* temp=*head;temp!=NULL;temp=temp->next)
    {
        for(node* temp2=temp->next; temp2!=NULL;temp2=temp2->next)
        {
            if(temp->timeComplexity>temp2->timeComplexity)
            {
                complexity temp_time=temp->timeComplexity;
                temp->timeComplexity=temp2->timeComplexity;
                temp2->timeComplexity=temp_time;

                complexity temp_space=temp->spaceComplexity;
                temp->spaceComplexity=temp2->spaceComplexity;
                temp2->spaceComplexity=temp_space;
            }
            else if(temp->timeComplexity==temp2->timeComplexity && temp->spaceComplexity>temp2->spaceComplexity)
            {
                complexity temp_time=temp->timeComplexity;
                temp->timeComplexity=temp2->timeComplexity;
                temp2->timeComplexity=temp_time;

                complexity temp_space=temp->spaceComplexity;
                temp->spaceComplexity=temp2->spaceComplexity;
                temp2->spaceComplexity=temp_space;
            }
        }
    }
}
void print(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        printf("%s %s\n",mapFromComplexity(temp->timeComplexity),mapFromComplexity(temp->spaceComplexity));
        temp=temp->next;
    }
}
int main()
{   node* head=NULL;
    getinput(&head);
    sort(&head);
    print(head);
    return 0;
}

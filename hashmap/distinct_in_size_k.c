#include<stdio.h>
#include<stdlib.h>

void take_input(int* input,int num)
{
    printf("enter the input array");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&input[i]);
    }
}
int main()
{   printf("enter the size of the array\n");
    int num;
    scanf("%d",&num);
    int* input=(int*)calloc(num,sizeof(int));
    take_input(input,num);
    int k;
    printf("enter the value of k\n");
    scanf("%d",&k);   
    int* freq=(int*)calloc(1000,sizeof(int));
    int start=0;
    int end=0;
    int count=0;
    if(num<k){printf("invalid");
    return 0; }
    while(end<k)
    {
        if(freq[input[end]]==0)
        {
            count++;
        }
        freq[input[end]]+=1;
        end++;
    }
    while(end<num)
    {
        printf("%d ",count);
        freq[input[start]]--;
        if(freq[input[start]]==0)
        {
            count--;
        }
        if(freq[input[end]]==0)
        {
            count++;
        }
        freq[input[end]]++;
        start++;
        end++;
        
    }
    printf("%d ",count);
    return 0;
}

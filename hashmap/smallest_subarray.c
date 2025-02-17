#include<stdio.h>
#include<stdlib.h>

int* take_input(int num)
{
    int* input=(int*)malloc(num*sizeof(int));
    for(int i=0;i<num;i++)
    {
        scanf("%d",&input[i]);
    }
    return input;
}
int* fill_frequency(int* input,int num,int* max,int* max_int)
{
    int* freq=(int*)calloc(num,sizeof(int));
    for(int i=0;i<num;i++)
    {
        freq[input[i]]++;
        if(freq[input[i]]>*max){
            *max=freq[input[i]];
            *max_int=input[i];
        }
    }
    return freq;
}
int main()
{
    int num;
    int max=0;
    int max_int=0;
    printf("enter the size of input\n");
    scanf("%d",&num);
    
    int* input=take_input(num);

    int* freq=fill_frequency(input,num,&max,&max_int);
    int start=-1;
    int end=-1;
    for(int i=0;i<num;i++)
    {
        if(input[i]==max_int && start==-1)
        {
            end=i;
            start=i;
        }
        else{
            end=i;
        }
    }
    printf("[%d %d]",start,end);
    free(input);
    free(freq);
    return 0;
}
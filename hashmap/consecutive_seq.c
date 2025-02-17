#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num;
    printf("enter the size of array\n");
    scanf("%d",&num);
    int* input=(int*)malloc(num*sizeof(int));
    int* freq=(int*)calloc(50,sizeof(int));
    printf("enter the array\n");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&input[i]);
        freq[input[i]]++;
    }
    int max=0;
    for(int i=0;i<50;i++)
    {
        int count=0;
        while(i<50 && freq[i]>0)
        {
            count++;
            i++;
        }
        max=max>count?max:count;
    }
    printf("answer is: %d",max);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int take_input(int* arr)
{
    int input;
    int index=0;
    while(scanf("%d",&input)==1)
    {
        arr[index]=input;
        index++;
        char ch=getchar();
        if(ch=='\n')
        {
            break;
        }
    }
    return index;
}
void insertion_sort(int* arr, int size)
{
    for(int i=0; i<size-1;i++)
    {
        for(int j =i+1;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else{
                break;
            }
        }
    }
}
int main()
{   int* arr=(int*)malloc(20*sizeof(int));
    int size=take_input(arr);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    insertion_sort(arr,size);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
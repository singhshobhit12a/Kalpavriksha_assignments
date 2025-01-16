#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
// int* take_input(int* size,int* k)
// {  
//     scanf("%d",&size);
//     int* arr=(int*)calloc(*size,sizeof(int));
//     for(int i=0;i<*size;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     scanf("%d",&k);
//     return arr;
// }
void rotate(int* arr,int start,int end)
{
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main()
{   int size,k;
    scanf("%d",&size);
    int* arr=(int*)calloc(size,sizeof(int));
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    if(k>=size)
    {
        k=k%size;
    }
    rotate(arr,0,size-1);
    rotate(arr,0,k-1);
    rotate(arr,k,size-1);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
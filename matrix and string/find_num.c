#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{   int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int** arr=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*) calloc(m,sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int target;
    scanf("%d",&target);
    int r=0;
    int c=m-1;
    while(r<n && c>0)
    {
        if(arr[r][c]==target)
        {
            printf("Found");
            return 0;
        }
        else if(arr[r][c]>target)
        {
            c--;
        }
        else{
            r++;
        }
    }
    printf("Not found");
    return 0;
}
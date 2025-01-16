#include<stdio.h>

int main()
{   int size;
    printf(" enter the size of pattern");
    scanf("%d",&size);
    //top portion of pattern
    for(int itr=0;itr<=size;itr++)
    {   //top left portion
        for(int itr2=1;itr2<=size;itr2++)
        {   if(itr2<=itr)
            { 
                printf("%d",itr2);
            }
            else
           {
            printf(" ");
           }
        }
        //top right portion
        for(int itr2=size;itr2>0;itr2--)
        {   if(itr2<=itr)
            {
            printf("%d",itr2);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    //bottom portion of pattern 
    for (int itr = size; itr >0; itr--)
    {   //bottom left pattern 
        for(int itr2=1;itr2<=size;itr2++)
        {
            if(itr>itr2)
            {
                printf("%d",itr2);
            }
            else{
                printf(" ");
            }
        }
        //bottom right
        for(int itr2=size;itr2>0;itr2--)
        {
            if((itr2<itr))
            {
                printf("%d",itr2);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int size_of(char* input)
{
    int length=0;
    while(*input!='\0')
    {
        length++;
        input++;
    }
    return length;
}
int check_palindrome(char* input,int start, int end)
{   int length=0;
    int even_odd=end-start+1;
    while(start<end)
    {
        if(input[start]!=input[end])
        {
            return -1;
        }
        length++;
        start++;
        end--;
    }
    if(even_odd%2==0)
    {return 2*length;}
    else return 2*length+1;
}
int main()
{   char input[100];
    int p_start=0;
    int p_end=0;
    scanf("%s",input);
    int n=size_of(input);
    if(n<2){
        printf("%s",input);
        return 0;
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        int start=i;
        int end=n-1;
        while(start<=end && input[start]!=input[end])
        {
            end--;
        }
        
        int temp_length=check_palindrome(input,start,end);
        if(temp_length>max)
        {
            max=temp_length;
            p_start=start;
            p_end=end;
        }
    }
    for(int i=p_start;i<=p_end;i++)
    {
        printf("%c",input[i]);
    }
    return 0;
}
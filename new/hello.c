// Write a program to find the longest word in a given sentence.

// Input: Hi Helo World, I am here.

// Output: 5
#include<stdio.h>
#include<stdlib.h>

int find_max_length(char* input)
{   printf("%s",input);
    char* start_point=input;
    int max_length=0;

    while(*start_point !='\0');
    {   int count=0;
       
        while(*start_point!=' ' && *start_point!='\0')
        {
            count++;
            start_point++; 
        }
        
        if(count>max_length)
        {
            max_length=count;
        }
        if(*start_point!='\0')
        {
            start_point++;
        }
    }
    return max_length;
}
int main()
{   
    char input[100];
    scanf("%[^\n]",input);
    printf("%d",find_max_length(input));
    return 0;
}
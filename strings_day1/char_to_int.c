// 5. Problem Statement: 
// Write a program to implement the atoi() function, which converts a string to an integer. The 
// function should handle negative numbers and return 0 for invalid input. 
// Sample Input and Output: 
// 1. Input: "1234" 
// Output: 1234 
// 2. Input: "-567" 
// Output: -567 
// 3. Input: "abc123" 
// Output: 0 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool is_digit(char input)
{
    return (input>='0' && input<='9');
}
int ch_to_int(char* input)
{   int temp=0;
    bool flag=false;
    if(*input=='-')
        {  
            flag=true;
            input++;
        }
    while(*input!='\0')
    {  
        if(is_digit(*input))
        {
            temp=((temp*10)+(*input-'0'));
        }
        else{
            return 0;
        }
        input++;
    }
    if(flag)
    {
        temp=-temp;
    }
    return temp;
}
int main()
{
    char input[10];
    scanf("%s",input);
    printf("%d",ch_to_int(input));
    return 0;
}
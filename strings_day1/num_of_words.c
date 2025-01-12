// Write a program to count the number of words in a given string. Assume words are separated 
// by one or more spaces, and the string may contain leading or trailing spaces. 
// Sample Input and Output: 
// 1. Input: "Hello World" 
// Output: 2 
// 2. Input: " The quick brown fox" 
// Output: 4 
// 3. Input: "This is a test " 
// Output: 4

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
char* take_input()
{
    char *input=(char*) calloc(100,sizeof(char));
    scanf("%[^\n]",input);
    return input;
}
bool is_alpha(char *input)
{
    return ((*input>='a' && *input<='z')||(*input>='A' && *input<='Z'));
}
int cal_words(char* input)
{   int words=0;
   
    while(*input!='\0')
    {   bool flag=0;
        while(*input==' ' || *input=='"')
        {
            input++;
        }
       while (is_alpha(input))
       {
        input++;
        flag=1;
       }
       if(flag)
       {
        words++;
       }
    }
    return words;
}
int main()
{
   char* input= take_input();
   printf("%d",cal_words(input));
   free(input);
}

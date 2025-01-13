#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int max_length(char* input)
{   int max_len=0;
    char* word_start=input;
    char* max_word=NULL;
    while(*input!='\0')
    {   int cur_len=0;
        
        while (*input!=' ' && *input!='\0')
        {
            cur_len++;
            input++;
        }
        
        if(cur_len>=max_len)
        {
            max_len=cur_len;
            max_word=word_start;
        }
        if(*input!='\0')
        {
            input++;
            word_start=input;
        }
    }
    for(int i=0;i<max_len;i++)
    {
        printf("%c",max_word[i]);
    }
    return max_len;
}

int main()
{
    char input[100];
    scanf("%[^\n]",input);
    max_length(input);
    return 0;
}
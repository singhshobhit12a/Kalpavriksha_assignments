#include<stdio.h>
#include<stdlib.h>
int str_len(char* input)
{   int count=0;
    while(*input!='\0')
    {
        count++;
        input++;
    }
    return count;
}
char* str_compress(char* input)
{   char* result=(char*)calloc(2*str_len(input),sizeof(char));
    int index=0;
    while(*input!='\0')
    {   int count=1;
        result[index]=*input;
        index++;
        while (*input==*(input+1))
        {
            count++;
            input++;
        }
        char ch_count=count+ '0';
        result[index]=ch_count;
        index++;
        input++;
    }
    result[index] = '\0';
    return result;
}
int main()
{
    char input[100];
    scanf("%[^\n]",input);
    char* compressed = str_compress(input);
    printf("%s\n", compressed);
    free(compressed);
    return 0;
}
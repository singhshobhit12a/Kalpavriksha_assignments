#include<stdio.h>
#include<stdlib.h>

void rem_ch(char* input,char ch)
{
    while(*input!='\0')
    {
        if(*input!=ch)
        {
            printf("%c",*input);  
        }
        input++;
    }
}
int main()
{
    char* input=(char*)calloc(50,sizeof(char));
    scanf("%[^\n]%*c",input);
    char ch;
    scanf("%c",&ch);
    rem_ch(input,ch);
    return 0;
}
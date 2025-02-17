#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


bool is_digit(char input)
{
    return input>='0' && input<='9';
}
char* take_input()
{
    char* input=(char*)calloc(15,sizeof(char));
    scanf("%s",input);
    return input;
}
int main()
{   int count_dot=0;
    char* input=take_input();
    bool dot=false;
    while(*input!='\0')
    {   bool first=true;
        bool zero=false;
        int temp=0;
        int count=0;
        if(!is_digit(*input)&& *input!='.') //not valid character
        {
            printf("invalid character case");
            return 0;
        }
        if(*input=='.' && dot)
        {
            printf("invalid dot case");
            return 0;
        }
        while(is_digit(*input))
        {
            if(first&&*input=='0') //leading 0 case
            {
                zero=true;
            }
            first=false;
            count++;
            temp=(temp*10)+(*input-'0');
            input++;
        }
        if(count>1 && zero)
        {
            printf("invalid zero case");
            return 0;
        }
        if(temp<0 || temp>255) //valid range case 
        {
            printf("invalid range case");
            return 0;
        }
        if(*input=='.')
        {
            dot=true;
            count_dot++;
            input++;
        }
        
    }
    if(count_dot!=3)
    {
        printf("dot count not matching"); //dot!=3 case.
        return 0;
    }
    printf("valid");
    return 0;
}
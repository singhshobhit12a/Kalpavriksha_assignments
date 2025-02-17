#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* create_lps(char* pattern,int pattern_size)
{   int index=0;
    int len=0;
    int* lps=(int*)calloc(pattern_size,sizeof(int));
    lps[index]=0;
    index++;
    while(index<pattern_size)
    {
        if(pattern[len]==pattern[index])
        {
            len++;
            lps[index]=len;
            index++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[index]=0;
                index++;
            }
        }
    }
    return lps;
}
int length(char * input)
{   int  length=0;
    while(*input!='\0')
    {   
        length++;
        input++;
    }
    return length;
}
bool find_pattern(int* lps, char*pattern,char* string,int pattern_size)
{   int i=0;
    int j=0;
    int string_length = length(string);
    while(i < string_length)
    {
        if(string[i]==pattern[j])
        {
            i++;
            j++;
        }
        if(j==pattern_size)
        {
            return true;
        }
        else if(i<string_length && string[i]!=pattern[j]){
            if(j!=0)
            {
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
        
    }
    return false;
}
int main()
{
    char string[100];
    char string2[100];
    printf("string1= ");
    scanf("%[^\n]%*c",string);
    printf("string2= ");
    scanf("%[^\n]%*c",string2);
    int string2_size=length(string2);
    char concat_string[string2_size];
    int index=0;
    for(int i=0;i<string2_size;i++)
    {
        concat_string[index]=string2[i];
        index++;
    }
    for(int i=0;i<string2_size;i++)
    {
        concat_string[index]=string2[i];
        index++;
    }
    int pattern_size=length(string);
    int*lps=create_lps(string,pattern_size*2);
    if(find_pattern(lps,string,concat_string,pattern_size)){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}
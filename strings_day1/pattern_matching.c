// Write a function to check if a given substring exists within a string. Return the starting index of 
// the substring if it exists; otherwise, return -1. 
// Sample Input and Output: 
// 1. Input: string = "hello world", substring = "world" 
// Output: 6 
// 2. Input: string = "programming", substring = "gram" 
// Output: 3 
// 3. Input: string = "abcdef", substring = "xyz" 
// Output: -1

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
int find_pattern(int* lps, char*pattern,char* string,int pattern_size)
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
            return i-pattern_size;
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
    return -1;
}
int main()
{
    char string[100];
    char pattern[100];
    printf("string= ");
    scanf("%[^\n]%*c",string);
    printf("pattern= ");
    scanf("%[^\n]%*c",pattern);
    int pattern_size=length(pattern);
    int*lps=create_lps(pattern,pattern_size);
    printf("%d",find_pattern(lps,pattern,string,pattern_size));
    return 0;
}
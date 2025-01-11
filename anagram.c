#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int check_length(char* input)
{ int length=0;
    while(*input!='\0')
    {
        length++;
        input++;
    }
    return length;
}
int* frequency(char * input,int* freq)
{   
    while(*input!='\0')
    {
        freq[*input-'a']+=1;
        input++;
    }
    return freq;
}
int main()
{
    char input1[100];
    char input2[100];
    
    scanf("%s",input1);
    scanf("%s",input2);
    
    int len1=check_length(input1);
    int len2=check_length(input2);
    
    if(len1!=len2)
    {
        printf("false");
        return 0;
    }
    
    int freq1[26]={0};
    int freq2[26]={0};
    
    frequency(input1,freq1);
    frequency(input2,freq2);

    for(int i=0;i<len1;i++)
    {
        if(freq1[i]!=freq2[i])
        {
            printf("false");
            return 0;
        }
    }
    printf("true");
    return 0;
}
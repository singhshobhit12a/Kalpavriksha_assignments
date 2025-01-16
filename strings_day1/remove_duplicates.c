// Write a program to remove all duplicate characters from a given string. The resulting string 
// should retain the order of first appearance of characters and should not contain any duplicate 
// letters. 
// Sample Input and Output: 
// 1. Input: "programming" 
// Output: "progamin" 
// 2. Input: "banana" 
// Output: "ban" 
// 3. Input: "abacabad" 
// Output: "abcd"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
char* take_input()
{
    char* input=(char *)calloc(100,sizeof(char));
    scanf("%s",input);
    return input;
}
void create_freq_arr(char* input)
{
    int* freq_arr= (int*)calloc(26,sizeof(int));
    printf("\"");
    while(*input!='\0')
    {   if(*input=='"')
        {
            input++;
        }
        if(freq_arr[*input-'a']==0)
        {
            printf("%c",*input);
            freq_arr[*input-'a']=1;
        }
        input++;
    }
    printf("\"");
    free(freq_arr);
}
int main()
{
    char* input=take_input();
    create_freq_arr(input);
    free(input);
    return 0;
}
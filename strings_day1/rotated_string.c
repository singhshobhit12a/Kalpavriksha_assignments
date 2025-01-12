// 4.Problem Statement: 
// Write a program to check if one string is a rotation of another string. For example, "abcd" and 
// "dabc" are rotations of each other. 
// Sample Input and Output: 
// 1. Input: string1 = "abcd", string2 = "dabc" 
// Output: true 
// 2. Input: string1 = "rotation", string2 = "ationrot" 
// Output: true 
// 3. Input: string1 = "hello", string2 = "world" 
// Output: false
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void take_input(char* string,int num)
{
    printf("string%d= ",num);
    scanf("%s",string);
}

int length(char* string)
{   int length=0;
    while(*string!='\0')
    {   
        length++;
        string++;
    }
    return length;
}
int check_rotaion(char*string1, char* string2)
{
    int index1=0;
    int index2=0;
    int rotation=0;
    int len1=length(string1);
    int len2=length(string2);
    
    if(len1!=len2)
    {
        printf("false");
        return 0;
    }
     while(rotation<len2 && string2[index2]!=string1[index1])
    {   
        index2++;
        rotation++;
        if(rotation==len2){
            printf("false");
            return 0;
        }
    }
    while(index1<len1)
    {
        if(string1[index1]==string2[index2])
        {
            index1++;
            index2=((index2+1)%len2);
        }
        else{
            printf("false");
            return 0;
        }
    }
    printf("true");
    return 0;
}

int main()
{   
    char string1[100];
    char string2[100];

    take_input(string1,1);
    take_input(string2,2);
    check_rotaion(string1,string2);    
   
    return 0;
}
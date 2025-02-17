#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int size_of(char* input)
{   int length=0;
    while(*input!='\0')
    {
        length++;
        input++;
    }
    return length;
}

char* remove_char(char* input)
{   
    if (input == NULL || *input == '\0') {
        return " "; 
    }

    char* new_str = (char*)calloc(size_of(input) + 1, sizeof(char));
    char* result = new_str;
    bool modified = false;

    while (*input != '\0')
    {   
        bool rep = false;
        if(!modified){
        while (*(input) != '\0' && *input == *(input + 1))
        { 
            rep = true;
            input++;  
        }

        if (rep) {
            input++;  
            modified = true;
        }
        }
        *new_str = *input;
        new_str++;
        input++;
    }

    *new_str = '\0';

    if (modified) {
        char* temp = remove_char(result);
        free(result);
        return temp;
    }

    return result;
}

char* take_input()
{
    char* input=(char*)calloc(50,sizeof(char));
    scanf("%s",input);
    return input;
}
int main()
{
    char* input=take_input();
    char* new=remove_char(input);
    printf("%s",new);
    return 0;
}
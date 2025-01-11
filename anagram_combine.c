#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void frequency(char * input,int* input_map)
{   
    while(*input!='\0')
    {
        input_map[*input-'a']+=1;
        input++;
    }
    
}
int main()
{   
    int max_strings;
    scanf("%d",&max_strings);

    char** input=(char**) calloc(max_strings,sizeof(char*));
    for(int i=0;i<max_strings;i++)
    {
        input[i]=calloc(50,sizeof(char));
        scanf("%s",input[i]);
    }

    int** input_map=(int **)calloc(max_strings,sizeof(int*));
    for(int i=0;i<max_strings;i++)
    {
        input_map[i]=calloc(26,sizeof(int));
        frequency(input[i],input_map[i]);
    }

   bool *processed = calloc(max_strings, sizeof(bool));  
    for (int i = 0; i < max_strings; i++) {
        if (processed[i]) {continue;}  

        printf("%s", input[i]);  
        processed[i] = true;     

       
        for (int j = i + 1; j < max_strings; j++) {
            if (processed[j]) {continue;}  

            bool is_anagram = true;
            for (int k = 0; k < 26; k++) {
                if (input_map[i][k] != input_map[j][k]) {
                    is_anagram = false;
                    break;
                }
            }

            if (is_anagram) {
                printf(" %s", input[j]);  
                processed[j] = true;     
            }
        }
        printf("\n");  
    }

    for (int i = 0; i < max_strings; i++)
    { 
        free(input[i]); 
        free(input_map[i]);
    } 

    free(input); 
    free(input_map);
    free(processed);
    return 0;
}
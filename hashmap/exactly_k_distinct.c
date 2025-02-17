#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char* input=(char*)malloc(100*sizeof(char));
    scanf("%s",input);
    int count=0;

    int* freq=(int*)calloc(26,sizeof(int));

    int k;
    scanf("%d",&k);

    int start=0;
    int end=0;
    int length=strlen(input);
    int max=-1;

    while(end<length)
    {
        if(freq[input[end]-'a']==0)
        {
            count++;
        }
        freq[input[end]-'a']+=1;
        end++;
        if(count>k)
        {
            while(start<=end && count>k)
            {
                freq[input[start]-'a']--;
                if(freq[input[start]-'a']==0)
                {
                    count--;
                }
                start++;
            }
        }
        max=max>(end-start)?max:end-start;
    }

    printf("%d",max);
    return 0;
}
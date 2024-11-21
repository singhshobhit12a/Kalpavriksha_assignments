#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int evaluate_expression(const char *expression, int *error)
{
    char *tokens=strdup(expression);
    char *token;
    int values[100];
    int top_values=-1;
    int operators[100];
    int top_operators=-1;

    int apply_operator(int a, int b, char op){
        switch(op){
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/':
                if(b==0)
                {
                    *error=1;
                    return 0;
                }
                return a/b;
            default: *error=1;
        }
        return 0;
    }
    
    void process_operator() {
        if (top_operators < 0 || top_values < 1) {
            *error = 1; 
            return;
        }
        int b = values[top_values--];
        int a = values[top_values--];
        char op = operators[top_operators--];
        values[++top_values] = apply_operator(a, b, op);
    }
    token=strtok(tokens," ");
    while(token!=NULL)
    {
        if(isdigit(token[0]))
        {
            values[++top_values]=atoi(token);
        }
        else if(is_operator(token[0]&& token[1]=='\n'))
        {
            while(top_operators>=0 &&  (token[0] == '+' || token[0] == '-') ||
                    (token[0] == '*' || token[0] == '/')
                )
                {
                    process_operator();
                    if(*error) break;
                }
                operators[++top_operators]=token[0];
        }
        else{
            *error=1;
            break;
        }
        token=strtok(NULL," ");
    }
    while (top_operators >= 0 && !*error) {
        process_operator();
    }
    free(tokens);
    if (top_values == 0 && !*error) {
        return values[top_values];
    }
    *error = 1;
    return 0;
}
int main()
{
    char input[100];
    printf("enter the expression for calculating: ");
    fgets(input,sizeof(input),stdin);
    int error = 0;
    int result = evaluate_expression(input, &error);
    if (error) {
        printf("Error: Invalid expression.\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}
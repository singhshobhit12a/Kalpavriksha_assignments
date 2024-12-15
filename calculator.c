#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int is_digit(char c)
{
    return c>=48 && c<=57;
}

int is_space(char c)
{
    return c==' ';
}
int str_len(const char *expression)
{   int count=0;
    while(expression[count]!='\0')
    {
        count++;
    }
    return count;
}

int check_precedence(char op,int *error) {
    if (op == '/') return 4;
    if (op == '*') return 3;
    if (op == '+') return 2;
    if (op == '-') return 1;
    *error=1;
    return 0;
}

int apply_operatation(int num_1, int num_2, char operator, int *error) {
    switch (operator) {
        case '+': return num_1 + num_2;
        case '-': return num_1 - num_2;
        case '*': return num_1 * num_2;
        case '/':
            if (num_2 == 0) {
                //printf("Error: Division by zero is not allowed\n");
                *error=2;
                return 0;
            }
            return num_1 / num_2;
        default:
            *error = 1; 
            return 0;
    }
}

void process_operator(int *number_stack, int *top_num_pointer, char *operator_stack, int *top_oper_pointer, int *error) {
    if (*top_oper_pointer < 0 || *top_num_pointer < 1 ) {
        *error = 1; 
        return;
    }
    int b = number_stack[(*top_num_pointer)--];
    int a = number_stack[(*top_num_pointer)--];
    char op = operator_stack[(*top_oper_pointer)--];
    number_stack[++(*top_num_pointer)] = apply_operatation(a, b, op, error);
    
}

int evaluate_expression(const char *expression, int *error) {
    int  number_stack[100], top_num_pointer = -1;
    char operator_stack[100];
    int top_oper_pointer = -1;
    
    int i = 0, n = str_len(expression); 
    while (i < n && *error==0) {
        if (is_space(expression[i])) {
            i++;
            continue;
        }

        if (is_digit(expression[i])) {
            int num = 0;
            while (i < n && is_digit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            number_stack[++top_num_pointer] = num;
        } 
        else if (is_operator(expression[i])) {
            while (top_oper_pointer >= 0 &&
                    check_precedence(operator_stack[top_oper_pointer],error) >= check_precedence(expression[i],error)) {
                    process_operator(number_stack, &top_num_pointer, operator_stack, &top_oper_pointer, error);
                    if(*error!=0)
                    {
                        return 0;
                    }
            }
            operator_stack[++top_oper_pointer] = expression[i];
            i++;
        } else {
            *error = 1; 
        }
    }

    while (top_oper_pointer >= 0 && *error==0) {
        process_operator(number_stack, &top_num_pointer, operator_stack, &top_oper_pointer, error);
    }
    if (*error != 0) return 0;

    if (top_num_pointer == 0 && *error==0) {
        return number_stack[top_num_pointer];
    }

    *error = 1; 
    return 0;
}

int main() {
    char input[100];
    printf("Enter the expression for calculation: ");
    scanf("%[^\n]%*c",input);
    
    int error = 0;
    int result = evaluate_expression(input, &error);

    if (error==1) {
        printf("Error: Invalid expression.\n");
    } 
    else if(error==2)
    {
        printf("Division by zero is not possible");
        
    }
    else {
        printf("Result: %d\n", result);
    }

    return 0;
}

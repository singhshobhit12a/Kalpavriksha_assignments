#include <stdio.h>

int col_num(char* input) {
    
    int temp = 0;
    while (*input != '\0') {
        temp = temp * 26 + (*input - 'A' + 1);
        input++;
    }
    return temp;
}

int main() {
    char input[10];
    scanf("%s", input);
    printf("%d\n", col_num(input));
    return 0;
}

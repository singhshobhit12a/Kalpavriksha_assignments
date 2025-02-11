#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void take_input(char** arr, int index) {
    char* word = (char*)malloc(100 * sizeof(char));
    scanf("%s", word);
    arr[index] = word;
}

void fill_freq(char** arr, int** freqs, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 26; j++) {
            freqs[i][j] = 0; 
        }
        for (int j = 0; j < 100 && arr[i][j] != '\0'; j++) {
            if (arr[i][j] >= 'a' && arr[i][j] <= 'z') { 
                freqs[i][arr[i][j] - 'a'] = 1; 
            }
        }
    }
}

int find_ans(char** arr, int** freqs, int num) {
    int max = 0;

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            int flag = 0;

            for (int k = 0; k < 26; k++) {
                if (freqs[i][k] && freqs[j][k]) {
                    flag = 1;  
                    break;
                }
            }

            if (!flag) {  
                int product = strlen(arr[i]) * strlen(arr[j]);
                if (product > max) {
                    max = product;
                }
            }
        }
    }
    printf("%d", max);
    return max;
}

int main() {
    int num;
    printf("Enter the number of words: ");
    scanf("%d", &num);

    char** arr = (char**)malloc(num * sizeof(char*));
    int** freqs = (int**)malloc(num * sizeof(int*));

    for (int i = 0; i < num; i++) {
        freqs[i] = (int*)malloc(26 * sizeof(int));
    }

    for (int i = 0; i < num; i++) {
        take_input(arr, i);
    }

    fill_freq(arr, freqs, num);
    find_ans(arr, freqs, num);


    return 0;
}
// ["abcw","baz","foo","bar","xtfn","abcdef"]
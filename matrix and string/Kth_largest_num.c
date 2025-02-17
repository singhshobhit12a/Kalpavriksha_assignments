#include<stdio.h>
#include<stdlib.h>

int find_largest(int* input, int size) {
    int max = *input;
    for (int i = 1; i < size; i++) {
        if (input[i] > max) {
            max = input[i];
        }
    }
    return max;
}

void count_frequencies(int* input, int size, int* freq, int max) {
    for (int i = 0; i < size; i++) {
        freq[input[i]]++;
    }
}

int process(int* freq, int max, int k) {
    int sum = 0;
    for (int i = max; i >= 0; i--) {
        sum += freq[i];
        if (sum >= k) {
            return i;
        }
    }
    return -1;
}

int find_kth_largest() {
    int size;
    printf("number of elements are: ");
    scanf("%d", &size);
    int k;
    printf("value of k is: ");
    scanf("%d", &k);

    int* input = (int*)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &input[i]);
    }

    int max = find_largest(input, size);
    int* freq = (int*)calloc(max + 1, sizeof(int));

    count_frequencies(input, size, freq, max);

    int result = process(freq, max, k);

    printf("%d largest element is: %d\n", k,result);

    free(input);
    free(freq);

    return 0;
}

int main() {
    find_kth_largest();
    return 0;
}

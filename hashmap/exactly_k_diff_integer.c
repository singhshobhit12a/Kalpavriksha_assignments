#include <stdio.h>
#include <stdlib.h>

int take_input(int* input, int num) {
    int max = -100000; // Handles negative numbers
    printf("Enter the array:\n");
    for (int i = 0; i < num; i++) {
        printf("%d- ", i);
        scanf("%d", &input[i]);
        if (input[i] > max) {
            max = input[i];
        }
    }
    return max;
}

// Function to count subarrays with at most k unique elements
int count_at_most_k(int* input, int num, int k) {
    if (k == 0) return 0; // Edge case

    int freq[100001] = {0}; // Assuming numbers are within reasonable range
    int left = 0, right = 0, count = 0, unique = 0, result = 0;

    while (right < num) {
        if (freq[input[right]] == 0) {
            unique++;
        }
        freq[input[right]]++;
        
        while (unique > k) { // Reduce window size
            freq[input[left]]--;
            if (freq[input[left]] == 0) {
                unique--;
            }
            left++;
        }
        
        result += (right - left + 1); // Count valid subarrays ending at `right`
        right++;
    }
    return result;
}

int main() {
    int num, k;
    printf("Enter the size of input array:\n");
    scanf("%d", &num);

    int* input = (int*)malloc(num * sizeof(int));
    take_input(input, num);

    printf("Enter the value of k:\n");
    scanf("%d", &k);

    int unique_exact_k = count_at_most_k(input, num, k) - count_at_most_k(input, num, k - 1);
    
    printf("%d\n", unique_exact_k);

    free(input); // Free allocated memory
    return 0;
}

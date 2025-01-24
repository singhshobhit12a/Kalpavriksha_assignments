#include <stdio.h>
#include <stdlib.h>

int fill_arr(int* arr) {
    int input;
    int index = 0;
    while (scanf("%d", &input) && index < 100) {
        arr[index] = input;
        index++;
        char ch = getchar();
        if (ch == '\n') {
            break;
        }
    }
    return index;
}

void find_comb(int* arr, int size, int index, int* res, int curr_index, int sum, int curr_sum) {
    if (curr_sum == sum) {
        for (int i = 0; i < curr_index; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
        return;
    }
    if (curr_sum > sum || index >= size) {
        return;
    }

    res[curr_index] = arr[index];
    find_comb(arr, size, index, res, curr_index + 1, sum, curr_sum + arr[index]);
    
    find_comb(arr, size, index + 1, res, curr_index, sum, curr_sum);
}

int main() {
    int* arr = (int*)malloc(100 * sizeof(int));
    
    int size = fill_arr(arr);
    int sum;
    scanf("%d", &sum);

    int* res = (int*)malloc(100 * sizeof(int));
    
    find_comb(arr, size, 0, res, 0, sum, 0);

    free(arr);
    free(res);
    return 0;
}

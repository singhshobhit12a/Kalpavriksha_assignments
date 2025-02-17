#include<stdio.h>
#include<stdlib.h>

void print(int** input, int* size) { 
    for(int i = 0; i < *size; i++) {
        for (int j = 0; j < *size; j++) {
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
}

void reverse(int** input, int row, int start, int end) {
    while (start < end) {
        int temp = input[row][start];
        input[row][start] = input[row][end];
        input[row][end] = temp;
        end--;
        start++;
    }
}

int** take_input(int* size) {
    int** input = (int**)calloc(*size, sizeof(int*));
    for(int i = 0; i < *size; i++) {
        input[i] = (int*)calloc(*size, sizeof(int));
    }
    for (int i = 0; i < *size; i++) {
        for(int j = 0; j < *size; j++) {
            scanf("%d", &input[i][j]);
        }
    }
    return input;  
}

void rotate(int** input, int *size) {
    // Transpose the matrix
    for(int i = 0; i < *size; i++) {
        for(int j = i + 1; j < *size; j++) {
            int temp = input[i][j];
            input[i][j] = input[j][i];
            input[j][i] = temp;
        }
    }
    // Reverse each row
    for (int i = 0; i < *size; i++) {
        int start = 0;
        int end = *size - 1;
        reverse(input, i, start, end);
    }
    // Print matrix after rotation
    print(input, size);
}

void left_rotate(int** input, int* size) {   
    int row; 
    printf("Enter row number: ");
    scanf("%d", &row);
    printf("Enter the value of k: ");
    int k;
    scanf("%d", &k);

    reverse(input, row, 0, *size - 1);
    reverse(input, row, 0, *size - k - 1);
    reverse(input, row, *size - k, *size - 1);
    print(input, size);
}

void right_rotate(int** input, int* size) {   
    int row; 
    printf("Enter row number: ");
    scanf("%d", &row);
    printf("Enter the value of k: ");
    int k;
    scanf("%d", &k);

    reverse(input, row, 0, *size - 1);
    reverse(input, row, 0, k - 1);
    reverse(input, row, k, *size - 1);
    print(input, size);
}

void reverse_col(int** input, int col, int start, int end) {
    while (start < end) {
        int temp = input[start][col];
        input[start][col] = input[end][col];
        input[end][col] = temp;
        end--;
        start++;
    }
}

void left_rotate_col(int** input, int* size) {   
    int col; 
    printf("Enter column number: ");
    scanf("%d", &col);
    printf("Enter the value of k: ");
    int k;
    scanf("%d", &k);

    reverse_col(input, col, 0, *size - 1);
    reverse_col(input, col, 0, *size - k - 1);
    reverse_col(input, col, *size - k, *size - 1);
    print(input, size);
}

void right_rotate_col(int** input, int* size) {   
    int col; 
    printf("Enter column number: ");
    scanf("%d", &col);
    printf("Enter the value of k: ");
    int k;
    scanf("%d", &k);

    reverse_col(input, col, 0, *size - 1);
    reverse_col(input, col, 0, k - 1);
    reverse_col(input, col, k, *size - 1);
    print(input, size);
}

int take_choice(int** input, int *size) {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        // Rotate array by 90 degrees
        rotate(input, size);
        break;
    case 2:
        // Left rotate row by k
        left_rotate(input, size);
        break;
    case 3:
        // Right rotate row by k
        right_rotate(input, size);
        break;
    case 4:
        // Left rotate column by k
        left_rotate_col(input, size);
        break;
    case 5:
        // Right rotate column by k
        right_rotate_col(input, size);
        break;
    case 6:
        // Exit
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
}

int main() {
    int size;
    printf("Enter the size of matrix: ");
    scanf("%d", &size);
    
    int** input = take_input(&size);
    while(1) {
        take_choice(input, &size);
    }

    for (int i = 0; i < size; i++) {
        free(input[i]);
    }
    free(input);

    return 0;
}

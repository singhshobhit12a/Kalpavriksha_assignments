#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue {
    int capacity;
    int head;
    int tail;
    int* arr;
} queue;

queue* create_queue(int capacity) {
    queue* Q = (queue*)malloc(sizeof(queue));
    Q->capacity = capacity;
    Q->head = -1;
    Q->tail = -1;
    Q->arr = (int*)malloc(capacity * sizeof(int));
    return Q;
}

bool isEmpty(queue* Q) {
    return (Q->head == -1);
}

bool isFull(queue* Q) {
    return (Q->tail >= Q->capacity - 1);
}

void push(queue* Q, int input) {
    if (isFull(Q)) {
        printf("The stack is full\n");
        return;
    }
    if (Q->head == -1) {
        Q->head = 0;
    }
    Q->tail += 1;
    Q->arr[Q->tail] = input;
}

void pop(queue* Q) {
    if (isEmpty(Q)) {
        printf("The stack is empty\n");
        return;
    }
    int size = Q->tail - Q->head;
    for (int i = 0; i < size; i++) {
        int temp = Q->arr[Q->head];
        for (int j = Q->head; j < Q->tail; j++) {
            Q->arr[j] = Q->arr[j + 1];
        }
        Q->arr[Q->tail] = temp;
    }
    Q->tail--;
    if (Q->tail < Q->head) {
        Q->head = -1;
        Q->tail = -1;
    }
}

void peek(queue* Q) {
    if (isEmpty(Q)) {
        printf("The stack is empty\n");
        return;
    }
    printf("%d is at the top of the stack\n", Q->arr[Q->tail]);
}

void size(queue* Q) {
    if (isEmpty(Q)) {
        printf("The size of stack is 0\n");
    } else {
        printf("The size of stack is %d\n", (Q->tail - Q->head) + 1);
    }
}

int main() {
    int capacity, input;
    printf("Enter the maximum capacity of the stack\n");
    scanf("%d", &capacity);
    queue* q1 = create_queue(capacity);

    printf("Choose actions to perform on stack:\n");
    printf("1 - Push\n2 - Pop\n3 - Peek\n4 - isEmpty\n5 - Size\n6 - Exit\n");
    
    while (1) {
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                scanf("%d", &input);
                push(q1, input);
                printf("Added %d to top of stack\n", input);
                break;
            case 2:
                pop(q1);
                printf("Popped from stack\n");
                break;
            case 3:
                peek(q1);
                break;
            case 4:
                if (isEmpty(q1)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                size(q1);
                break;
            case 6:
                exit(0);
                break;
            default:
            printf("invalid input\n");
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void create_list(node** head) {
    node* prev = *head;
    int input;
    while (scanf("%d", &input) == 1) {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = input;
        temp->next = NULL;
        if (*head == NULL) {
            *head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        char ch = getchar();
        if (ch == '\n') {
            break;
        }
    }
}

void get_output(int result, int target, int position) {
    if (result) {
        printf("\n%d is found at position %d\n", target, position);
    } else {
        printf("\n%d is not found\n", target);
    }
}

int linear_search(node* head, int target, int* position) {
    while (head != NULL) {
        (*position)++;
        if (head->data == target) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    int target;
    int position = 0;
    node* head = NULL;

    printf("Enter values for the linked list:\n");
    create_list(&head);

    printf("Enter target value: ");
    scanf("%d", &target);

    int result = linear_search(head, target, &position);
    get_output(result, target, position);

    return 0;
}

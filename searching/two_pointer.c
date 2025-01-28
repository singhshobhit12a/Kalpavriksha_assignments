#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
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

void get_output(int result, int target) {
    if (result) {
        printf("\n%d is found\n", target);
    } else {
        printf("\n%d is not found\n", target);
    }
}

node* get_tail(node* head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

int search_two_pointers(node* head, node* tail, int target) {
    while (head != tail) {
        if (head->data == target || tail->data == target) {
            return 1;
        }
        if (head->next == tail) {
            return 0;
        }
        head = head->next;
        tail = tail->prev;
    }
    return head->data == target;
}

int main() {
    int target;
    node* head = NULL;

    printf("Enter values for the linked list:\n");
    create_list(&head);

    printf("Enter target value: ");
    scanf("%d", &target);

    node* tail = get_tail(head);
    int result = search_two_pointers(head, tail, target);
    get_output(result, target);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void make_list(node** head) {
    int input;
    node* prev = *head;
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

node* find_mid(node** head) {
    node* slow = *head;
    node* fast = (*head)->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* left, node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    node* merged = NULL;
    if (left->data < right->data) {
        merged = left;
        merged->next = merge(left->next, right);
    } else {
        merged = right;
        merged->next = merge(left, right->next);
    }
    return merged;
}

void merge_sort(node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    node* mid = find_mid(head);
    node* right_head = mid->next;
    mid->next = NULL;

    merge_sort(head);
    merge_sort(&right_head);

    *head = merge(*head, right_head);
}

void print_list(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    make_list(&head);

    printf("Original list: ");
    print_list(head);

    merge_sort(&head);

    printf("Sorted list: ");
    print_list(head);

    return 0;
}

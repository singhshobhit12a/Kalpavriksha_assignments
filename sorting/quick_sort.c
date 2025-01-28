#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* take_input(node** head) {
    int input;
    node* tail = NULL;
    while (scanf("%d", &input) == 1) {
        node* temp = (node*)malloc(sizeof(node));
        temp->data = input;
        temp->next = NULL;
        temp->prev = tail;

        if (*head == NULL) {
            *head = temp;
        } else {
            tail->next = temp;
        }
        tail = temp;

        char ch = getchar();
        if (ch == '\n') {
            break;
        }
    }
    return tail;
}

node* partition(node* head, node* tail) {
    int pivot = tail->data;
    node* i = head->prev;
    for (node* j = head; j != tail; j = j->next) {
        if (j->data <= pivot) {
            i = (i == NULL) ? head : i->next;
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
    i = (i == NULL) ? head : i->next;
    int temp = i->data;
    i->data = tail->data;
    tail->data = temp;
    return i;
}

void quick_sort(node* head, node* tail) {
    if (head != NULL && tail != NULL && head != tail && head->prev != tail) {
        node* pivot = partition(head, tail);
        quick_sort(head, pivot->prev);
        quick_sort(pivot->next, tail);
    }
}

void print_list(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    node* tail = take_input(&head);

    quick_sort(head, tail);

    print_list(head);

    while (head != NULL) {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

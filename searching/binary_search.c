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

void get_output(int result, int target) {
    if (result) {
        printf("\n%d is found\n", target);
    } else {
        printf("\n%d is not found\n", target);
    }
}

int get_length(node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

int binary_search(node** low, int target) {
    int len = get_length(*low);
    if ((*low)->next == NULL) {
        return (*low)->data == target;
    }
    int mid_index = len / 2;

    node* mid_node = *low;
    int count = 1;
    while (count != mid_index) {
        mid_node = mid_node->next;
        count++;
    }

    if (mid_node->data == target) {
        return 1;
    } else if (mid_node->data < target) {
        return binary_search(&(mid_node->next), target);
    } else {
        mid_node->next = NULL;
        return binary_search(low, target);
    }
}

int main() {
    int target;
    node* head = NULL;

    printf("Enter values for the linked list:\n");
    create_list(&head);

    printf("Enter target value: ");
    scanf("%d", &target);

    int result = binary_search(&head, target);
    get_output(result, target);

    return 0;
}

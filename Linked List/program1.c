// Enter elements and display the inserted elements
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} *Node;

void accept(Node *r, int n) {
    int i;
    Node temp;

    for (i = 0; i < n; i++) {
        if (*r == NULL) {
            *r = temp = (Node)malloc(sizeof(struct Node)); //used to create new linked list nodes dynamically at runtime.
            scanf("%d", &temp->data);
        } else {
            temp->next = (Node)malloc(sizeof(struct Node));
            temp = temp->next;
            scanf("%d", &temp->data);
        }
    }
    temp->next = NULL;
}

void display(Node head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;
    Node root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    accept(&root, n);
    printf("Linked List: ");
    display(root);

    return 0;
}
// Enter number of elements: 5
// 1 2 3 4 5
// Linked List: 1 2 3 4 5
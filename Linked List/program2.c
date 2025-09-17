//insert elements- append, display and InsertFirst
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void append(Node **r, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if ((*r) == NULL)
    {
        (*r) = newNode;
    }
    else
    {
        Node *temp = (*r);
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

void insertFirst(Node **r, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = (*r);
    (*r) = newNode;
}

int main()
{
    Node *head = NULL;
    int ch, data;

    while (1)
    {
        printf("\n1. Append\n2. Display\n3. Insert First\n4. Exit\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Data: ");
            scanf("%d", &data);
            append(&head, data);
            break;

        case 2:
            display(head);
            break;

        case 3:
            printf("Enter Data: ");
            scanf("%d", &data);
            insertFirst(&head, data);
            break;

        case 4:
            return 0;

        default:
            printf("INVALID CHOICE !!!\n");
        }
    }
}
/*
1. Append
2. Display
3. Insert First
4. Exit
Enter Choice: 1
Enter Data: 30

1. Append
2. Display
3. Insert First
4. Exit
Enter Choice: 2
30

1. Append
2. Display
3. Insert First
4. Exit
Enter Choice: 3
Enter Data: 40

1. Append
2. Display
3. Insert First
4. Exit
Enter Choice: 2
40
30

1. Append
2. Display
3. Insert First
4. Exit
Enter Choice: 4
*/
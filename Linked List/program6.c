// insert elements - append, display, InsertFirst, InsertInBetween
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

void insertInBetween(Node **head, int data, int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (pos == 1) 
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) 
    {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *head = NULL;
    int ch, data, pos;

    while (1)
    {
        printf("\n1. Append\n2. Display\n3. Insert First\n4. Insert In Between\n5. Exit\nEnter Choice: ");
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
            printf("Enter Position: ");
            scanf("%d", &pos);
            printf("Enter Data: ");
            scanf("%d", &data);
            insertInBetween(&head, data, pos);
            break;

        case 5:
            return 0;

        default:
            printf("INVALID CHOICE !!!\n");
        }
    }
}
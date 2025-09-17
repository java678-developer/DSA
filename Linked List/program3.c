//append, display, Insertfirst.
#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    int roll;
    char name[100];
    float marks;
} Student;

typedef struct Node
{
    Student s;
    struct Node *next;
} Node;

void append(Node **r, Student data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->s = data;
    newNode->next = NULL;

    if (*r == NULL)
    {
        *r = newNode;
    }
    else
    {
        Node *temp = *r;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        printf("Roll: %d\n", head->s.roll);
        printf("Name: %s\n", head->s.name);
        printf("Marks: %f\n\n", head->s.marks);
        head = head->next;
    }
}

void insertFirst(Node **r, Student data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->s = data;
    newNode->next = *r;
    *r = newNode;
}

int main()
{
    Node *head = NULL;
    int ch;

    while (1)
    {
        printf("\n1. Append\n2. Display\n3. Insert First\n4. Exit\nEnter Choice: \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            Student s;
            printf("Enter Roll: ");
            scanf("%d", &s.roll);
            printf("Enter Name: ");
            scanf(" %s", s.name);
            printf("Enter Marks: ");
            scanf("%f", &s.marks);
            append(&head, s);
            break;
        }
        case 2:
            display(head);
            break;

        case 3:
        {
            Student s;
            printf("Enter Roll: ");
            scanf("%d", &s.roll);
            printf("Enter Name: ");
            scanf(" %s", &s.name);
            printf("Enter Marks: ");
            scanf("%f", &s.marks); // ok even if we dont use & here
            insertFirst(&head, s);
            break;
        }

        case 4:
            return 0;

        default:
            printf("INVALID CHOICE !!!\n");
        }
    }
}
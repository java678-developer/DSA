//Student program to search roll no
#include <stdio.h>
#include <stdlib.h>

typedef struct Student  //Part 1
{
    int roll;
    char name[100];
    float marks;
} Student;

typedef struct Node //Part 2
{
    Student s;
    struct Node *next;
} Node;

Student inputStudent() //Part 3
{
    Student s;
    printf("Enter Roll: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %s", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);
    return s;
}

void append(Node **r, Student data) //Part 4
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

void insertFirst(Node **r, Student data) //Part 5
{ 
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->s = data;
    newNode->next = *r;
    *r = newNode;
}

void display(Node *head) //Part 6
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    while (head != NULL)
    {
        printf("Roll: %d, Name: %s, Marks: %.2f\n",
               head->s.roll, head->s.name, head->s.marks);
        head = head->next;
    }
}

void search(Node *head, int roll) //Part 7
{ 
    while (head != NULL)
    {
        if (head->s.roll == roll)
        {
            printf("Student Found!\n");
            printf("Roll: %d\n, Name: %s\n, Marks: %f\n",
                   head->s.roll, head->s.name, head->s.marks);
            return;
        }
        head = head->next;
    }
    printf("Student with Roll %d not found!\n", roll);
}

int main() //Part 8
{
    Node *head = NULL;
    int ch;

    while (1)
    {
        printf("\n1. Append\n2. Display\n3. Insert First\n4. Search\n5. Exit\nEnter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            Student s = inputStudent();
            append(&head, s);
            break;
        }
        case 2:
            display(head);
            break;
        case 3:
        {
            Student s = inputStudent();
            insertFirst(&head, s);
            break;
        }
        case 4:
        {
            int roll;
            printf("Enter Roll Number to Search: ");
            scanf("%d", &roll);
            search(head, roll);
            break;
        }
        case 5:
            return 0;
        default:
            printf("INVALID CHOICE !!!\n");
        }
    }
}
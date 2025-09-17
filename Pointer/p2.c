#include<stdio.h>
#include<stdlib.h>

void swap(int *p, int *q){
int temp=*p;
*p=*q;
*q=temp;
}

int main()
{
    int a,b;
    system("cls");
    printf("Enter Two Numbers: ");
    scanf("%d%d",&a, &b);

    swap(&a,&b);

    printf("After swapping 1= %d, 2= %d", a, b);
}
// Pointer 
// Used for dynamic memory allocation
// Pointer is a derived data type
// size of every pointer is 4 byte// void pointer generic pointer which stores address of any variable
// A pointer stores address of other pointer is called chain pointer
// A pointer only stores address of variable which belongs to same datatype for eg. int*p will store only int data taype
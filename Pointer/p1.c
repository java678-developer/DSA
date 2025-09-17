#include <stdio.h>
int main()
{
    int a[100], *p, i, n;
    p = &a[0];
    printf("Enter N:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);
    printf("Given data is: ");
    for (i = 0; i < n; i++)
        printf("%d ", p[i]);
    return 0;
}
// accept and print the nos program
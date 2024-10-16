#include <stdio.h>
int main()
{
    int a[20], n, i, j, count = 0;
    printf("Enter number of bits: ");
    scanf("%d", &n);
    printf("Enter bits: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
            count++;
        else
            count = 0;
        if (count == 5)
        {
            for (j = n; j > i; j--)
                a[j] = a[j - 1];
            a[++i] = 0;
            n++;
            count = 0;
        }
    }
    printf("01111110 ");
    for (i = 0; i < n; i++)
        printf("%d", a[i]);
    printf(" 01111110\n");
    return 0;
}

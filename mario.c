#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Enter the size of the pyramid: ");
        scanf("%i", &n);
    } while (n < 1);

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j < n; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
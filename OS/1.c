#include <stdio.h>
#include <unistd.h>
int main()
{
    int n;
    printf("enter n:");
    scanf("%d", &n);
    while (n != 0)
    {
        printf("Multiple fork Statements");
        n--;
    }
    return 0;
}

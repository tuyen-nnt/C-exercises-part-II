#include <stdio.h>
#include <stdlib.h>

//Xuat day Fibonacci su dung de quy:
int F(int n)
{
    if (n == 0)
        return 0;

    if (n <= 2)
            return 1;

    return (F(n - 1) + F(n - 2));
}

int main() {
    int n = 0;
    char buffer[10];

    do
    {
        printf("Nhap vao so nguyen duong n >= 0, n = ");
        scanf("%s", buffer);
        n = (int) strtol(buffer, NULL, 10);
    } while (n < 0);

    printf("Day Fibonacci F0 den Fn la: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", F(i));
    }

    return 0;
}
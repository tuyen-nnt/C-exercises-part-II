#include <stdio.h>
#include <stdlib.h>

//Su dung thuat toan de quy Euclid tim UCLN
int UCLN(int a, int b)
{
    /*Cach 1:
     * while (a != b)
    {
        if (a > b) {
            a = a - b;
        } else {
            b = a - b;
        }
    }
    return a;*/

    if (b == 0)
        return a;

    return UCLN(b, a % b);

}

int main() {
    int a = 0;
    int b = 0;
    char buffer[10];

    do{
        printf("Nhap vao 2 so nguyen duong a,b >= 0! \n");
        printf("a = ");
        scanf("%s", buffer);
        a = (int) strtol(buffer, NULL, 10);

        printf("b = ");
        scanf("%s", buffer);
        b = (int) strtol(buffer, NULL, 10);
    } while ((a < 0) || (b < 0));

    if (a >= b)
        printf("UCLN = %d", UCLN(a, b));
    else
        printf("UCLN = %d", UCLN(b, a));

    return 0;
}
//

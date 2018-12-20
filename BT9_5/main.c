#include <stdio.h>
#include <stdlib.h>

int main() {
    int k = 0;
    char buffer[10];
    char c;
    char d;

    printf("Nhap vao so nguyen K de lam khoa! k = ");
    scanf("%s", buffer);
    k = (int) strtol(buffer, NULL, 10);

    FILE *ip;
    ip = fopen("input.txt", "r");

    FILE *op;
    op = fopen("mahoa.txt", "w");

    //Cau a) Tao file mat lenh ma hoa tu file van ban
    while ((c = fgetc(ip)) != EOF)
    {
        if (c == 32)
            fputc(c, op);
        else
            if (((c+k) > 122) || (((c+k) > 90) && ((c+k) < 97)))
                fputc(c + k - 26, op);
            else
                fputc(c+k, op);
    }

    fclose(ip);
    fclose(op);

// Cau b) Giai ma 1 file mat lenh thanh file van ban

    FILE *matlenh;
    matlenh = fopen("matlenh.txt", "r");

    FILE *giaima;
    giaima = fopen("giaima.txt", "w");

    while ((d = fgetc(matlenh)) != EOF)
    {
        if (d == 32)
            fputc(d, giaima);
        else
            if (((d - k) < 65) || (((d - k) > 90) && ((d - k) < 97)))
                fputc(d - k + 26, giaima);
            else
                fputc(d - k, giaima);
    }

    fclose(matlenh);
    fclose(giaima);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct HocSinh
{
    char hoten[50];
    float van;
    float toan;
    float dtb;
};

void nhapDanhSach(struct HocSinh **hocSinh, int* n)
{
    FILE *file;
    file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Could not open file input.txt");
        exit(0);
    }

    fscanf(file, "%d\n", &(*n));

    *hocSinh = (struct HocSinh*)malloc(*n * sizeof(struct HocSinh));

    for (int i = 0; i < *n; i++)
    {
        fscanf(file, "%[a-zA-Z0-9 ] ", (*hocSinh)[i].hoten);
        fscanf(file, "%1f", &(*hocSinh)[i].van);
        fscanf(file, "%1f", &(*hocSinh)[i].toan);
        fscanf(file, "\n");
    }

    for (int i = 0; i < *n; i++)
    {
        (*hocSinh)[i].dtb = ((*hocSinh)[i].van + (*hocSinh)[i].toan) / 2;
    }

    fclose(file);
}


void dsgioi(struct HocSinh **hocSinh, int n)
{
    FILE *file;
    file = fopen("output.txt", "w");

    struct HocSinh t;

    for (int k = 0; k < n; k++)
    {
        for (int i = n - 1; i >= 0; i++)
        {
            if ((*hocSinh)[k].dtb < (*hocSinh)[k].dtb)
            {
                t = (*hocSinh)[k];
                (*hocSinh)[k] = (*hocSinh)[k + 1];
                (*hocSinh)[k + 1] = t;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((*hocSinh)[i].dtb >= 8)
        {
            fprintf(file,"Danh sach hs gioi theo thu tu : \n");
            fprintf(file,"Ho ten: %s\n", (*hocSinh)[i].hoten);

            fprintf(file,"Diem trung binh: %f\n", (*hocSinh)[i].dtb);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if ((*hocSinh)[i].dtb >= 8)
        {
            printf("Danh sach hs gioi theo thu tu :\n");
            printf("Ho ten: %s\n", (*hocSinh)[i].hoten);

            printf("Diem trung binh: %f\n", (*hocSinh)[i].dtb);
        }
    }
    fclose(file);
}

int main() {

    int n = 0;

    struct HocSinh *hocSinh;

    nhapDanhSach(&hocSinh,&n);

    for (int i = 0; i < n; i++)
    {
        printf("%s  ", hocSinh[i].hoten);
        printf("%2.1f  ", hocSinh[i].van);
        printf("%.1f\n", hocSinh[i].toan);
    }

    printf("\n");

    dsgioi(&hocSinh, n);

    return 0;
}

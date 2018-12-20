#include <stdio.h>
#include <memory.h>
#define MAX 100

int main() {

    FILE *f1;
    f1 = fopen("file1.txt", "rb");

    FILE *f2;
    f2 = fopen("file2.txt", "rb");


    // Open file to store the result
    FILE *f3 = fopen("file3.txt", "wb");
    char c[100];
    //char s;

    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        scanf("Could not open files");
        return 0;
    }

    //c = fread(s, sizeof(char), 100, f1)
     int soluong;
    // Copy contents of first file to file3.txt
    do {

        soluong = fread(c, 1, MAX, f1);
        fwrite(c, 1, soluong, f3);
    } while (soluong != EOF);

    // Copy contents of second file to file3.txt
    do {
        soluong = fread(c, 1, MAX, f2);
        fwrite(c, 1, soluong, f3);
    } while (soluong != EOF);

    /*// Copy contents of first file to file3.txt
   while ((c = fgetc(fp1)) != EOF)
      fputc(c, fp3);

   // Copy contents of second file to file3.txt
   while ((c = fgetc(fp2)) != EOF)
      fputc(c, fp3);
        */

    printf("Merged file1.txt and file2.txt into file3.txt");

    fclose(f1);
    fclose(f2);
    fclose(f3);

    /*do
    {
        printf("Nhap vao duong dan file 1: ");
        scanf("%s", buffer);
    } while (buffer == NULL);

    fprintf(file, "%s\n", buffer);

    do
    {
        printf("Nhap vao duong dan file 2: ");
        scanf("%s", buffer);
    } while (buffer == NULL);

    fprintf(file, "%s", buffer);*/
    return 0;
}
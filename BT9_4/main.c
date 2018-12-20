#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
int main()
{
    char buffer[100] = {};

    printf("Nhap vao duong dan file 1: ");
    scanf("%s", buffer);

    FILE *f = fopen(buffer, "w+");

    if(f == NULL)
    {
     printf("Error!");
     exit(1);
    }

    printf("%s\n", buffer);

    printf("Enter a text, press ESC to stop: \n");

    char exit = 0;

    while (1)
    {
        exit = getchar();
        if (exit != 27)
        {
            fputc(exit, f);
        } else break;
    }

  /*  do
    {
        exit = getchar();
        fputc(exit ,f);
    } while(exit != 27);
*/
    fclose(f);

 return 0;
}

//CACH CUA BAO:::
/*
 #include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char inputFile[100];

    char output[100] = {};
    int outputLength = 0;

    printf("Enter file to save: ");
    scanf("%s", inputFile);
    printf("Entering text editor...");

    while (1)
    {
        char ch = (char) getchar();
        if (ch == 27)
        {
            break;
        } else
        {
            output[outputLength++] = ch;
        }
    }

    FILE* f = fopen(inputFile, "w");
    fwrite(output, outputLength, sizeof(char), f);
    fclose(f);

    return 0;
}
 */
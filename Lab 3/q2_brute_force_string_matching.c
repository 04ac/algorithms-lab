#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[50];
    char pattern[50];
    int i, j;

    printf("Enter text \n");
    scanf("%s", text);

    printf("Enter pattern \n");
    scanf("%s", pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    for (i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            printf("Substring found at index %d\n", i);
            return 0;
        }
    }
    printf("Substring not found\n");
}
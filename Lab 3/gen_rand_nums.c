#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *fp;
    fp = fopen("nums.txt", "w");
    for (int i = 1; i <= 100; i++)
    {
        int num = rand() % 100 + 1; // use rand() function to get the random number
        fprintf(fp, "%d ", num);
    }
    fclose(fp);
}
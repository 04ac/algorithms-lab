#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, opCount = 0;

	printf("Enter input size\n");
	scanf("%d", &n);

	int a[n];

	printf("Enter numbers\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			opCount++;
			if (a[j] > a[j + 1])
			{
				// Swap
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	printf("Sorted: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");


	printf("Input size: %d\nOp Count: %d\n", n, opCount);
}

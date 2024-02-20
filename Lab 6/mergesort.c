#include <stdio.h>

int opcnt = 0;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m; // r - (m + 1) + 1

    int a1[n1];
    int a2[n2];

    for (int i = 0; i < n1; i++)
    {
        a1[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        a2[i] = arr[m + 1 + i];
    }
    
    int c = l; // Not 0
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        opcnt++;
        if (a1[i] > a2[j]) {
            arr[c++] = a2[j++];
        } else {
            arr[c++] = a1[i++];
        }
    }

    while (i < n1) {
        opcnt++;
        arr[c++] = a1[i++];
    }

    while (j < n2) {
        opcnt++;
        arr[c++] = a2[j++];
    }
}

void mergesort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    printf("Enter no of elements\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("OpCount: %d\n", opcnt);
}
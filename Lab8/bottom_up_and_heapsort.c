#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapBottomUp(int arr[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        int k = i;
        int v = arr[k];
        int heap = 0;

        while (!heap && 2*k <= n) {
            int j = 2*k;
            if (j < n) {
                // there are 2 chldren
                if (arr[j] < arr[j+1]) {
                    j++;
                }
            }

            if (v >= arr[j]) {
                heap = 1;
            } else {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr + largest, arr + i);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(arr + i, arr);
        heapify(arr, i, 0);
    }
}

int main() {
    printf("Enter no. of elements\n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter numbers\n");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    heapBottomUp(arr, n);
    printf("Heap: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, n);
    printf("Sorted Heap: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

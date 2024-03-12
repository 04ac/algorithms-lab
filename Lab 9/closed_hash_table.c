#include <stdio.h>
#include <stdlib.h>

int key_comparisons = 0;

int hashFunc(int v, int SIZE) {
    return v % SIZE;
}

void insertHT(int v, int n, int hash[]) {
    int i = hashFunc(v, n);

    if (hash[i] == __INT_MAX__) {
        hash[i] = v;
        return;
    }

    int ini = i;
    do  {
        i = (i + 1) % n;
    } while (hash[i] != __INT_MAX__ && i != ini);

    if (i == ini) {
        printf("Insertion not possible\n");
    } else {
        hash[i] = v;
    }
}

int searchHT(int v, int n, int hash[]) {
    int i = hashFunc(v, n);
    key_comparisons = 0;

    key_comparisons++;
    if (hash[i] == v)
        return 1;

    int ini = i;
    do  {
        i = (i + 1) % n;
        key_comparisons++;
    } while (hash[i] != v && i != ini);

    return i != ini;
}

int main() {
    int n, v = 0, d;
    printf("Enter hash table size\n");
    scanf("%d", &n);

    // Hash table
    int hash[n];

    for (int i = 0; i < n; i++)
    {
        hash[i] = __INT_MAX__;
    }

    printf("Enter 1 to insert, 2 to search, -1 to exit\n");
    while (v != -1)
    {
        printf("Enter choice.\n");
        scanf("%d", &v);

        switch (v)
        {
            case 1:
                printf("Enter value to insert\n");
                scanf("%d", &d);
                insertHT(d, n, hash);
                break;
            case 2:
                printf("Enter value to search\n");
                scanf("%d", &d);
                printf(searchHT(d, n, hash) == 1 ? "Found\n" : "Not Found\n");
                printf("Key comparisons: %d\n", key_comparisons);
                break;
            default:
                break;
        }
    }
}
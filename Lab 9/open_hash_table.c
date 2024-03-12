#include <stdio.h>
#include <stdlib.h>
#define null NULL

int key_comparisons = 0;

typedef struct Node
{
    struct Node* next;
    int val;
} Node;

Node* newNode(int v) {
    Node* n = malloc(sizeof(Node));
    n->val = v;
    n->next = null;
}

int hashFunc(int v, int SIZE) {
    return v % SIZE;
}

void insertHT(int v, int idx, Node* hash[]) {
    Node* p = hash[idx]->next;

    if (p == null) {
        hash[idx]->next = newNode(v);
        return;
    }

    while (p->next)
    {
        p = p->next;
    }

    p->next = newNode(v);
}

int searchHT(int v, int idx, Node* hash[]) {
    Node* p = hash[idx]->next;
    key_comparisons = 0;
    
    while (p != null)
    {
        key_comparisons++;
        if (p->val == v) {
            break;
        }
        p = p->next;
    }

    return p != null;
}

int main() {
    int n, v = 0, d;
    printf("Enter hash table size\n");
    scanf("%d", &n);

    Node* hash[n];

    for (int i = 0; i < n; i++)
    {
        hash[i] = newNode(i);
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
                int idx = hashFunc(d, n);
                insertHT(d, idx, hash);
                break;
            case 2:
                printf("Enter value to search\n");
                scanf("%d", &d);
                idx = hashFunc(d, n);
                printf(searchHT(d, idx, hash) == 1 ? "Found\n" : "Not Found\n");
                printf("Key comparisons: %d\n", key_comparisons);
                break;
            default:
                break;
        }
    }
}

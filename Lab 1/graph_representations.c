#include <stdio.h>
#include <stdlib.h>

typedef struct Node* Nodeptr;

typedef struct Node
{
    int val;
    Nodeptr next;
} Node;

Nodeptr newNode(int v) {
    Nodeptr n = malloc(sizeof(Node));
    n->next = NULL;
    n->val = v;
}

int main() {
    int n;
    int v;
    printf("Enter no. of vertices?\n");
    scanf("%d", &n);

    int mat[n][n];
    Nodeptr adjList[n];

    printf("Enter 1 for Yes, 0 for No\n");
    for (int i = 0; i < n; i++) {

        adjList[i] = newNode(i+1);

        for (int j = 0; j < n; j++) {
            if (i == j) {
                mat[i][j] = 0;
                continue;
            }
            printf("Is there an edge b/w vertex %d and %d\n", i + 1, j + 1);
            scanf("%d", &v);

            if (v == 1) {
                mat[i][j] = 1;
                Nodeptr ptr = adjList[i];

                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }

                ptr->next = newNode(j+1);

            } else if (v == 0) {
                mat[i][j] = 0;
            } else {
                printf("Invalid input. Try again\n");
                i--; j--;
            }
        }
    }

    printf("Displaying adj. mat:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Displaying adj. list: \n");
    for (int i = 0; i < n; i++) {
        Nodeptr ptr = adjList[i];

        while (ptr != NULL) {
            printf("%d -> ", ptr->val);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

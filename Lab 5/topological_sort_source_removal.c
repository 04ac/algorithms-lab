#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* newNode(int v) {
    Node* n = malloc(sizeof(Node));
    n->val = v;
    n->next = NULL;
    return n;
}

typedef struct Queue {
    int q[MAX];
    int f;
    int r;
} Queue;

void insertQ(int n, Queue* q) {
    if (q->r == MAX - 1) {
        printf("Queue full");
        return;
    }

    (q->q)[++(q->r)] = n;
}

int deleteQ(Queue *q) {
    if (q->r == q->f) {
        printf("Queue empty\n");
        return -9999;
        
    }
    return (q->q)[++(q->f)];
}

int isEmpty(Queue *q) {
    return q->r == q->f;
}

void topSortSourceRemoval(Node** adj, int V, int e) {
    int *indeg = calloc(V, sizeof(int));
    Queue *q = malloc(sizeof(Queue));

    // Set up indegree list
    for (int i=0; i<V; i++) {
        Node* p = adj[i]->next;
        while (p != NULL) {
            indeg[p->val]++;
            p = p->next;
        }
    }

    for (int i=0; i<V; i++) {
        if (indeg[i] == 0) {
            insertQ(i, q);
        }
    }

    printf("Topological sort order: \n");
    while (!isEmpty(q)) {
        int curr = deleteQ(q);
        printf("%d ", curr);

        Node *p = adj[curr]->next;
        while (p != NULL) {
            if (--indeg[p->val] == 0) {
                insertQ(p->val, q);
            }
            p = p->next;
        }
    }
}

int main() {
    printf("Enter no. of vertices and edges\n");
    int V, e;
    scanf("%d%d", &V, &e);

    Node* adj[V+1];

    for (int i = 0; i < V; i++)
    {
        adj[i] = newNode(i);
    }

    printf("Enter edges\n");
    for (int i=0; i<e; i++) {
        printf("Enter edge %d\n", i+1);
        int u, v;
        scanf("%d%d", &u, &v);

        Node* p = adj[u];
        while (p->next) {
            p = p->next;
        }
        p->next = newNode(v);
    }

    topSortSourceRemoval(adj, V, e);
    printf("\n");
}
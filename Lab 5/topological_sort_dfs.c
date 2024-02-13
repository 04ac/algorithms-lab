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

typedef struct Stack {
    int s[MAX];
    int tos;
} Stack;

void push(Stack *s, int v) {
    if (s->tos == MAX - 1)
        printf("Stack Full!\n");
    s->s[++(s->tos)] = v;
}

int pop(Stack *s) {
    if (s->tos == -1) {
        printf("Stack empty!");
        return -9999;
    }
    return s->s[(s->tos)--];
}

void topSortDfs(Stack *s, Node **adj, int curr, int vis[]) {
    vis[curr] = 1;

    Node* p = adj[curr]->next;

    while (p != NULL) {
        if (!vis[p->val])
            topSortDfs(s, adj, p->val, vis);
        p = p->next;
    }

    push(s, curr);
}

int main() {
    printf("Enter no. of vertices and edges\n");
    int V, e;
    scanf("%d%d", &V, &e);

    Node* adj[V+1];
    int vis[V+1];

    for (int i = 0; i < V; i++)
    {
        adj[i] = newNode(i);
        vis[i] = 0;
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

    Stack *s = malloc(sizeof(Stack));
    s->tos = -1;

    for (int i=0; i<V; i++) {
        if (!vis[i])
            topSortDfs(s, adj, i, vis);
    }

    while (s->tos != -1)
    {
        printf("%d ", pop(s));
    }
    printf("\n");
}
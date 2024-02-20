#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
} Node;

int num_nodes(Node* root, int *opcnt) {
    (*opcnt)++;
    if (root == NULL) {
        return 0;
    }

    return 1 + num_nodes(root->left, opcnt) + num_nodes(root->right, opcnt);
}

Node* insertBST(Node* root, int v) {
    if (root == NULL) {
        Node* n = malloc(sizeof(Node));
        n->val = v;
        return n;
    }

    if (v < root->val) {
        root->left = insertBST(root->left, v);
    } else if (v > root->val) {
        root->right = insertBST(root->right, v);
    } else {
        printf("Duplicates not allowed\n");
    }
    return root;
}

int main() {
    Node* root = NULL;
    int n, opcnt = 0;
    printf("Enter no. of nodes\n");
    scanf("%d", &n);

    printf("Enter nodes\n");
    for (int i=0; i<n; i++) {
        int v;
        scanf("%d", &v);
        root = insertBST(root, v);
    }

    printf("Total num of nodes in bin tree = %d\n", num_nodes(root, &opcnt));
    printf("Op count: %d\n", opcnt);
}
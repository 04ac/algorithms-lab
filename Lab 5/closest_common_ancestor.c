#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int v) {
    Node* n = malloc(sizeof(Node));
    n->val = v;
    n->left = NULL;
    n->right = NULL;
    return n;
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

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

Node* getCCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == n1 || root->val == n2) {
        return root;
    }

    Node* left_cca = getCCA(root->left, n1, n2);
    Node* right_cca = getCCA(root->right, n1, n2);

    if (left_cca != NULL && right_cca != NULL) {
        return root;
    }

    if (left_cca == NULL) {
        return right_cca;
    } else {
        return left_cca;
    }
}

int main() {
    Node* root = NULL;
    int n;
    printf("Enter no. of nodes\n");
    scanf("%d", &n);

    printf("Enter nodes\n");
    for (int i=0; i<n; i++) {
        int v;
        scanf("%d", &v);
        root = insertBST(root, v);
    }

    printf("Enter nums for cca\n");
    int u, v;
    scanf("%d%d", &u, &v);
    Node* cca = getCCA(root, u, v);
    printf("CCA: %d\n", cca->val);
}

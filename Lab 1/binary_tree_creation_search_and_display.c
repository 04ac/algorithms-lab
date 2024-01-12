#include <stdio.h>
#include <stdlib.h>

typedef struct Node* Nodeptr;

typedef struct Node
{
    int val;
    Nodeptr left;
    Nodeptr right;
} Node;

Nodeptr newNode(int v) {
    Nodeptr n = malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->val = v;
}

Nodeptr insertBST(int v, Nodeptr root) {
    if (root == NULL) {
        return newNode(v);
    }

    if (v < (root)->val) {
        root->left = insertBST(v, (root)->left);
    } else if (v > (root)->val) {
        root->right =  insertBST(v, (root)->right);
    } else {
        printf("No duplicates allowed\n");
    }
    return root;
}

int search(int key, Nodeptr root) {
    Nodeptr ptr = root;
    if (root == NULL) return 0;

    if (key == root->val) {
        return 1;
    }

    if (key < root->val) {
        return search(key, root->left);
    } else {
        return search(key, root->right);
    }
}

void inorder(Nodeptr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(Nodeptr root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Nodeptr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}

int main() {
    int a[5] = {1, 5, 4, 7, 0};
    int n = 5;
    Nodeptr root = NULL;

    for (int i = 0; i < 5; i++) {
        root = insertBST(a[i], root);
    }

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    printf("%s\n", search(5, root) ? "Found" : "Not found");
    printf("%s\n", search(8, root) ? "Found" : "Not found");
}

#pragma once
#include <stdio.h>
#include <stdlib.h>

// 레드-블랙 트리 노드 구조체
typedef enum { RED, BLACK } Color;

typedef struct Node11 {
    int key;
    Color color;
    struct Node11* left, * right, * parent;
} Node11;

Node11* createNode11(int key) {
    Node11* newNode = (Node11*)malloc(sizeof(Node11));
    newNode->key = key;
    newNode->color = RED;  // 새로운 노드는 레드로 삽입됩니다.
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void rotateLeft(Node11** root, Node11* x) {
    Node11* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rotateRight(Node11** root, Node11* y) {
    Node11* x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void fixViolation(Node11** root, Node11* z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node11* y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(root, z->parent->parent);
            }
        }
        else {
            Node11* y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

Node11* insert11(Node11* root, int key) {
    Node11* z = createNode11(key);
    Node11* y = NULL;
    Node11* x = root;

    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    fixViolation(&root, z);
    return root;
}

void inorder11(Node11* root) {
    if (root != NULL) {
        inorder11(root->left);
        printf("%d ", root->key);
        inorder11(root->right);
    }
}

void RedBlackTree(void) {
    int close = 1;
    Node11* root = NULL;
    int choice, value;

    do {
        printf("\n레드-블랙 트리 작업 메뉴:\n");
        printf("1. 삽입\n");
        printf("2. 출력 (중위 순회)\n");
        printf("3. 종료\n");
        printf("작업을 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 값을 입력하세요: ");
            scanf_s("%d", &value);
            root = insert11(root, value);
            break;
        case 2:
            printf("중위 순회 출력: ");
            inorder11(root);
            printf("\n");
            break;
        case 3:
            printf("종료합니다...\n");
            break;
        default:
            printf("잘못된 선택입니다. 올바른 선택지를 입력하세요.\n");
        }
    } while (choice != 3);

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

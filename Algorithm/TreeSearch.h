#pragma once
#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 구조체
typedef struct Node10 {
    int key;
    struct Node10* left;
    struct Node10* right;
} Node10;

// 새 노드 생성
Node10* newNode(int item) {
    Node10* temp = (Node10*)malloc(sizeof(Node10));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// 이진 트리에 값 삽입
Node10* insert10(Node10* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert10(node->left, key);
    else if (key > node->key)
        node->right = insert10(node->right, key);

    return node;
}

// 이진 트리에서 값 검색
Node10* search(Node10* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

// 주어진 노드의 가장 작은 값을 찾음
Node10* minValueNode(Node10* node) {
    Node10* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// 이진 트리에서 값 삭제
Node10* deleteNode(Node10* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node10* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node10* temp = root->left;
            free(root);
            return temp;
        }

        Node10* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// 이진 트리를 중위 순회하여 값 출력
void inorder(Node10* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// 메모리 해제
void freeTree(Node10* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void TreeSearch(void) {
    int close = 1;
    Node10* root = NULL;
    int choice, value;

    do {
        printf("\n이진 검색 트리 작업 메뉴:\n");
        printf("1. 삽입\n");
        printf("2. 검색\n");
        printf("3. 삭제\n");
        printf("4. 출력 (중위 순회)\n");
        printf("5. 종료\n");
        printf("작업을 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 값을 입력하세요: ");
            scanf_s("%d", &value);
            root = insert10(root, value);
            break;
        case 2:
            printf("찾을 값을 입력하세요: ");
            scanf_s("%d", &value);
            if (search(root, value) != NULL)
                printf("값 %d을(를) 트리에서 찾았습니다.\n", value);
            else
                printf("값 %d을(를) 트리에서 찾지 못했습니다.\n", value);
            break;
        case 3:
            printf("삭제할 값을 입력하세요: ");
            scanf_s("%d", &value);
            root = deleteNode(root, value);
            break;
        case 4:
            printf("중위 순회 출력: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            freeTree(root);
            printf("종료합니다...\n");
            break;
        default:
            printf("잘못된 선택입니다. 올바른 선택지를 입력하세요.\n");
        }
    } while (choice != 5);

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T 3 // B-트리의 최소 차수

typedef struct BTreeNode {
    int* keys; // 키 배열
    int degree; // 현재 노드의 키 개수
    struct BTreeNode** childPtr; // 자식 노드 포인터 배열
    bool leaf; // 리프 노드 여부
} BTreeNode;

BTreeNode* createNode12() {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->keys = (int*)malloc(sizeof(int) * (2 * T - 1));
    newNode->childPtr = (BTreeNode**)malloc(sizeof(BTreeNode*) * (2 * T));
    newNode->leaf = true;
    newNode->degree = 0;
    return newNode;
}

void traverse(BTreeNode* root) {
    int i;
    for (i = 0; i < root->degree; i++) {
        if (root->leaf == false) {
            traverse(root->childPtr[i]);
        }
        printf(" %d", root->keys[i]);
    }
    if (root->leaf == false) {
        traverse(root->childPtr[i]);
    }
}

void splitChild(BTreeNode* parentNode, int index, BTreeNode* childNode) {
    BTreeNode* newNode = createNode12();
    newNode->leaf = childNode->leaf;
    newNode->degree = T - 1;

    for (int j = 0; j < T - 1; j++) {
        newNode->keys[j] = childNode->keys[j + T];
    }

    if (!childNode->leaf) {
        for (int j = 0; j < T; j++) {
            newNode->childPtr[j] = childNode->childPtr[j + T];
        }
    }

    childNode->degree = T - 1;

    for (int j = parentNode->degree; j >= index + 1; j--) {
        parentNode->childPtr[j + 1] = parentNode->childPtr[j];
    }
    parentNode->childPtr[index + 1] = newNode;

    for (int j = parentNode->degree - 1; j >= index; j--) {
        parentNode->keys[j + 1] = parentNode->keys[j];
    }
    parentNode->keys[index] = childNode->keys[T - 1];

    parentNode->degree++;
}

void insertNonFull(BTreeNode* node, int key) {
    int i = node->degree - 1;
    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->degree++;
    }
    else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->childPtr[i]->degree == 2 * T - 1) {
            splitChild(node, i, node->childPtr[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->childPtr[i], key);
    }
}

void insert12(BTreeNode** root, int key) {
    BTreeNode* temp = *root;
    if (temp == NULL) {
        *root = createNode12();
        (*root)->keys[0] = key;
        (*root)->degree = 1;
    }
    else {
        if (temp->degree == 2 * T - 1) {
            BTreeNode* newNode = createNode12();
            newNode->childPtr[0] = temp;
            newNode->leaf = false;
            splitChild(newNode, 0, temp);
            int i = 0;
            if (newNode->keys[0] < key) {
                i++;
            }
            insertNonFull(newNode->childPtr[i], key);
            *root = newNode;
        }
        else {
            insertNonFull(temp, key);
        }
    }
}

void BTree(void) {
    int close = 1;
    BTreeNode* root = NULL;
    int value, choice;

    do {
        printf("\nB-트리 작업 메뉴:\n");
        printf("1. 삽입\n");
        printf("2. 출력 (중위 순회)\n");
        printf("3. 종료\n");
        printf("작업을 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 값을 입력하세요: ");
            scanf_s("%d", &value);
            insert12(&root, value);
            break;
        case 2:
            printf("트리 내 키 값:");
            traverse(root);
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

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T 3 // B-Ʈ���� �ּ� ����

typedef struct BTreeNode {
    int* keys; // Ű �迭
    int degree; // ���� ����� Ű ����
    struct BTreeNode** childPtr; // �ڽ� ��� ������ �迭
    bool leaf; // ���� ��� ����
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
        printf("\nB-Ʈ�� �۾� �޴�:\n");
        printf("1. ����\n");
        printf("2. ��� (���� ��ȸ)\n");
        printf("3. ����\n");
        printf("�۾��� �����ϼ���: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("������ ���� �Է��ϼ���: ");
            scanf_s("%d", &value);
            insert12(&root, value);
            break;
        case 2:
            printf("Ʈ�� �� Ű ��:");
            traverse(root);
            printf("\n");
            break;
        case 3:
            printf("�����մϴ�...\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ùٸ� �������� �Է��ϼ���.\n");
        }
    } while (choice != 3);

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

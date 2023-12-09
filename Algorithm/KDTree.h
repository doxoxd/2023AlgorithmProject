#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point {
    int x, y;
} Point;

typedef struct KDNode {
    Point point;
    struct KDNode* left, * right;
} KDNode;

KDNode* insertNode(KDNode* root, Point point, int depth) {
    if (root == NULL) {
        KDNode* newNode = (KDNode*)malloc(sizeof(KDNode));
        newNode->point = point;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    int cd = depth % 2; // 2���� ������ �ٷ�Ƿ� 2�� ���� �������� ����

    if (cd == 0) { // x ��ǥ�� �������� ����
        if (point.x < root->point.x)
            root->left = insertNode(root->left, point, depth + 1);
        else
            root->right = insertNode(root->right, point, depth + 1);
    }
    else { // y ��ǥ�� �������� ����
        if (point.y < root->point.y)
            root->left = insertNode(root->left, point, depth + 1);
        else
            root->right = insertNode(root->right, point, depth + 1);
    }

    return root;
}

void inorderTraversal(KDNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("(%d, %d) ", root->point.x, root->point.y);
        inorderTraversal(root->right);
    }
}

void KDTree(void) {
    int close = 1;
    KDNode* root = NULL;
    int numPoints;

    printf("������ ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &numPoints);

    printf("%d���� ���� x, y ��ǥ�� ���ʴ�� �Է��ϼ���:\n", numPoints);
    for (int i = 0; i < numPoints; i++) {
        Point point;
        printf("�� %d�� x ��ǥ: ", i + 1);
        scanf_s("%d", &point.x);
        printf("�� %d�� y ��ǥ: ", i + 1);
        scanf_s("%d", &point.y);
        root = insertNode(root, point, 0);
    }

    printf("���� ��ȸ ���: ");
    inorderTraversal(root);
    printf("\n");

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

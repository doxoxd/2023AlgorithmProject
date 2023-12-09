#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point2 {
    int x, y, z;
} Point2;

typedef struct KDBNode {
    Point2 point;
    struct KDBNode* left, * middle, * right;
} KDBNode;

KDBNode* insertNode13(KDBNode* root, Point2 point, int depth) {
    if (root == NULL) {
        KDBNode* newNode = (KDBNode*)malloc(sizeof(KDBNode));
        newNode->point = point;
        newNode->left = newNode->middle = newNode->right = NULL;
        return newNode;
    }

    int cd = depth % 3; // 3���� ������ �ٷ�Ƿ� 3���� ���� �������� ����

    if (cd == 0) { // x ��ǥ�� �������� ����
        if (point.x < root->point.x)
            root->left = insertNode13(root->left, point, depth + 1);
        else if (point.x == root->point.x)
            root->middle = insertNode13(root->middle, point, depth + 1);
        else
            root->right = insertNode13(root->right, point, depth + 1);
    }
    else if (cd == 1) { // y ��ǥ�� �������� ����
        if (point.y < root->point.y)
            root->left = insertNode13(root->left, point, depth + 1);
        else if (point.y == root->point.y)
            root->middle = insertNode13(root->middle, point, depth + 1);
        else
            root->right = insertNode13(root->right, point, depth + 1);
    }
    else { // z ��ǥ�� �������� ����
        if (point.z < root->point.z)
            root->left = insertNode13(root->left, point, depth + 1);
        else if (point.z == root->point.z)
            root->middle = insertNode13(root->middle, point, depth + 1);
        else
            root->right = insertNode13(root->right, point, depth + 1);
    }

    return root;
}

void inorderTraversal13(KDBNode* root) {
    if (root != NULL) {
        inorderTraversal13(root->left);
        printf("(%d, %d, %d) ", root->point.x, root->point.y, root->point.z);
        inorderTraversal13(root->middle);
        inorderTraversal13(root->right);
    }
}

void KDBTree(void) {
    int close = 1;
    KDBNode* root = NULL;
    int numPoints;

    printf("������ ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &numPoints);

    printf("%d���� ���� x, y, z ��ǥ�� ���ʷ� �Է��ϼ���:\n", numPoints);
    for (int i = 0; i < numPoints; i++) {
        Point2 point;
        printf("�� %d�� x ��ǥ: ", i + 1);
        scanf_s("%d", &point.x);
        printf("�� %d�� y ��ǥ: ", i + 1);
        scanf_s("%d", &point.y);
        printf("�� %d�� z ��ǥ: ", i + 1);
        scanf_s("%d", &point.z);
        root = insertNode13(root, point, 0);
    }

    printf("���� ��ȸ ���: ");
    inorderTraversal13(root);
    printf("\n");

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_POINTS 4 // �� ���� ����Ʈ �ִ� ����

typedef struct Point3 {
    int x, y;
} Point3;

typedef struct RTNode {
    bool isLeaf;
    int numPoints;
    Point3 points[MAX_POINTS];
    struct RTNode* children[MAX_POINTS + 1];
} RTNode;

RTNode* createNode14() {
    RTNode* newNode = (RTNode*)malloc(sizeof(RTNode));
    newNode->isLeaf = true;
    newNode->numPoints = 0;
    for (int i = 0; i < MAX_POINTS + 1; ++i)
        newNode->children[i] = NULL;
    return newNode;
}

void insertPoint(RTNode* root, Point3 point) {
    if (root->numPoints < MAX_POINTS) {
        root->points[root->numPoints++] = point;
    }
    else {
        // Implement splitting logic here
    }
}

void inorderTraversal2(RTNode* root) {
    if (root != NULL) {
        for (int i = 0; i < root->numPoints; ++i) {
            printf("(%d, %d) ", root->points[i].x, root->points[i].y);
        }
        for (int i = 0; i < root->numPoints + 1; ++i) {
            inorderTraversal2(root->children[i]);
        }
    }
}

void RTree(void) {
    int close = 1;
    RTNode* root = createNode14();
    int numPoints;

    printf("������ ���� ������ �Է��ϼ���: ");
    scanf_s("%d", &numPoints);

    printf("%d���� ���� x, y ��ǥ�� ���ʷ� �Է��ϼ���:\n", numPoints);
    for (int i = 0; i < numPoints; ++i) {
        Point3 point;
        printf("�� %d�� x ��ǥ: ", i + 1);
        scanf_s("%d", &point.x);
        printf("�� %d�� y ��ǥ: ", i + 1);
        scanf_s("%d", &point.y);
        insertPoint(root, point);
    }

    printf("���� ��ȸ ���: ");
    inorderTraversal2(root);
    printf("\n");

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

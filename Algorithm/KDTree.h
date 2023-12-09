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

    int cd = depth % 2; // 2차원 공간을 다루므로 2로 나눈 나머지가 차원

    if (cd == 0) { // x 좌표를 기준으로 분할
        if (point.x < root->point.x)
            root->left = insertNode(root->left, point, depth + 1);
        else
            root->right = insertNode(root->right, point, depth + 1);
    }
    else { // y 좌표를 기준으로 분할
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

    printf("삽입할 점의 개수를 입력하세요: ");
    scanf_s("%d", &numPoints);

    printf("%d개의 점의 x, y 좌표를 차례대로 입력하세요:\n", numPoints);
    for (int i = 0; i < numPoints; i++) {
        Point point;
        printf("점 %d의 x 좌표: ", i + 1);
        scanf_s("%d", &point.x);
        printf("점 %d의 y 좌표: ", i + 1);
        scanf_s("%d", &point.y);
        root = insertNode(root, point, 0);
    }

    printf("중위 순회 결과: ");
    inorderTraversal(root);
    printf("\n");

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

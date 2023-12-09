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

    int cd = depth % 3; // 3차원 공간을 다루므로 3으로 나눈 나머지가 차원

    if (cd == 0) { // x 좌표를 기준으로 분할
        if (point.x < root->point.x)
            root->left = insertNode13(root->left, point, depth + 1);
        else if (point.x == root->point.x)
            root->middle = insertNode13(root->middle, point, depth + 1);
        else
            root->right = insertNode13(root->right, point, depth + 1);
    }
    else if (cd == 1) { // y 좌표를 기준으로 분할
        if (point.y < root->point.y)
            root->left = insertNode13(root->left, point, depth + 1);
        else if (point.y == root->point.y)
            root->middle = insertNode13(root->middle, point, depth + 1);
        else
            root->right = insertNode13(root->right, point, depth + 1);
    }
    else { // z 좌표를 기준으로 분할
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

    printf("삽입할 점의 개수를 입력하세요: ");
    scanf_s("%d", &numPoints);

    printf("%d개의 점의 x, y, z 좌표를 차례로 입력하세요:\n", numPoints);
    for (int i = 0; i < numPoints; i++) {
        Point2 point;
        printf("점 %d의 x 좌표: ", i + 1);
        scanf_s("%d", &point.x);
        printf("점 %d의 y 좌표: ", i + 1);
        scanf_s("%d", &point.y);
        printf("점 %d의 z 좌표: ", i + 1);
        scanf_s("%d", &point.z);
        root = insertNode13(root, point, 0);
    }

    printf("중위 순회 결과: ");
    inorderTraversal13(root);
    printf("\n");

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

#pragma once
#include <stdio.h>
#include <limits.h>

#define N 5 // ������ ��

int minCost = INT_MAX; // �ּ� ����� �����ϴ� ����
int finalPath[N]; // ���� �ּ� ��� ��θ� �����ϴ� �迭
int visited[N]; // �湮�� ���ø� ǥ���ϴ� �迭
int graph[N][N] = {
    {0, 10, 15, 20, 25},
    {10, 0, 35, 25, 30},
    {15, 35, 0, 30, 35},
    {20, 25, 30, 0, 20},
    {25, 30, 35, 20, 0}
};

void printGraph() {
    printf("���� �� ��� �׷���:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void printPath(int path[N]) {
    printf("�ּ� ��� ���: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int isSafe2(int v, int k, int path[N]) {
    if (!graph[path[k - 1]][v]) // ���� ��ο��� ���� ���÷� �̵��� �� ���� ���
        return 0;
    for (int i = 0; i < k; i++) { // �̹� �湮�� ������ ���
        if (path[i] == v)
            return 0;
    }
    return 1;
}

void tsp2(int path[N], int k, int cost) {
    if (k == N) { // ��� ���ø� �湮�� ���
        if (graph[path[k - 1]][path[0]]) { // ������ ���ÿ��� ��� ���÷� �� �� �ִ� ���
            if (cost + graph[path[k - 1]][path[0]] < minCost) {
                minCost = cost + graph[path[k - 1]][path[0]];
                for (int i = 0; i < N; i++) {
                    finalPath[i] = path[i];
                }
            }
        }
        return;
    }

    for (int v = 1; v < N; v++) {
        if (isSafe2(v, k, path)) {
            path[k] = v;
            tsp2(path, k + 1, cost + graph[path[k - 1]][v]);
            path[k] = -1;
        }
    }
}

void Prunning(void) {
    int close = 1;
    int path[N];

    printGraph(); // �׷��� ���

    for (int i = 0; i < N; i++) {
        path[i] = -1;
    }
    path[0] = 0; // ���� ���ô� 0��° ����

    tsp2(path, 1, 0);

    if (minCost == INT_MAX) {
        printf("��ΰ� �������� �ʽ��ϴ�.\n");
    }
    else {
        printPath(finalPath);
        printf("�ּ� ���: %d\n", minCost);
    }

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

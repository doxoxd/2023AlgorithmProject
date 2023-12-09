#pragma once
#include <stdio.h>

#define N 5 // ������ ��

// ���� ���� Ʈ���� ���� TSP�� ���� ���¸� ���� ���� ��Ÿ��

void tsp(int current, int visited, int graph[N][N], int path[N], int path_index, int* min_cost) {
    if (visited == (1 << N) - 1) { // ��� ���ø� �湮���� ��
        int total_cost = graph[current][0]; // ���� ���÷� ���ư��� ���
        printf("���: 0");
        for (int i = 1; i <= path_index; ++i) {
            printf(" -> %d", path[i]);
            total_cost += graph[path[i - 1]][path[i]];
        }
        total_cost += graph[path[path_index]][0];
        printf(" -> 0 (�� ���: %d)\n", total_cost);

        if (total_cost < *min_cost) {
            *min_cost = total_cost;
        }
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!(visited & (1 << i))) { // i��° ���ø� �湮���� �ʾ��� ��
            path[path_index + 1] = i;
            tsp(i, visited | (1 << i), graph, path, path_index + 1, min_cost);
        }
    }
}

void StateSpaceTree(void) {
    int close = 1;
    int graph[N][N] = {
        {0, 10, 10, 30, 25},
        {10, 0, 14, 21, 10},
        {10, 18, 0, 7, 9},
        {8, 11, 7, 0, 3},
        {14, 10, 10, 3, 0}
    };

    int path[N]; // ��� ���� �迭
    path[0] = 0; // ���� ���ô� 0�� ���÷� ����
    int min_cost = 999999; // �ּ� ��� �ʱ�ȭ

    printf("\n���� �� ��� �׷���:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nTSP ��� ����:\n");
    tsp(0, 1, graph, path, 0, &min_cost);

    printf("\n�ּ� ���: %d\n", min_cost);

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

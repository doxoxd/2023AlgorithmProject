#pragma once
#include <stdio.h>
#include <limits.h>

#define N 5 // 도시의 수

int minCost = INT_MAX; // 최소 비용을 저장하는 변수
int finalPath[N]; // 최종 최소 비용 경로를 저장하는 배열
int visited[N]; // 방문한 도시를 표시하는 배열
int graph[N][N] = {
    {0, 10, 15, 20, 25},
    {10, 0, 35, 25, 30},
    {15, 35, 0, 30, 35},
    {20, 25, 30, 0, 20},
    {25, 30, 35, 20, 0}
};

void printGraph() {
    printf("도시 간 비용 그래프:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void printPath(int path[N]) {
    printf("최소 비용 경로: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

int isSafe2(int v, int k, int path[N]) {
    if (!graph[path[k - 1]][v]) // 현재 경로에서 다음 도시로 이동할 수 없는 경우
        return 0;
    for (int i = 0; i < k; i++) { // 이미 방문한 도시인 경우
        if (path[i] == v)
            return 0;
    }
    return 1;
}

void tsp2(int path[N], int k, int cost) {
    if (k == N) { // 모든 도시를 방문한 경우
        if (graph[path[k - 1]][path[0]]) { // 마지막 도시에서 출발 도시로 갈 수 있는 경우
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

    printGraph(); // 그래프 출력

    for (int i = 0; i < N; i++) {
        path[i] = -1;
    }
    path[0] = 0; // 시작 도시는 0번째 도시

    tsp2(path, 1, 0);

    if (minCost == INT_MAX) {
        printf("경로가 존재하지 않습니다.\n");
    }
    else {
        printPath(finalPath);
        printf("최소 비용: %d\n", minCost);
    }

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

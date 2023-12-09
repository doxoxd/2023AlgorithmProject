#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 10
#define INF 987654321

// 사이클이 없는 그래프의 최단 경로
int V, E;
int adj[MAX_V][MAX_V];

void initAdj2() {
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) {
            adj[i][j] = INF;
            if (i == j) adj[i][j] = 0;
        }
}

void dijkstra2(int start) {
    int visited[MAX_V] = { 0 };
    int distance[MAX_V];
    int i, j, min_index, min_value;

    for (i = 0; i < V; i++) {
        distance[i] = adj[start][i];
    }

    visited[start] = 1;
    distance[start] = 0;

    for (i = 0; i < V - 1; i++) {
        min_value = INF;
        for (j = 0; j < V; j++) {
            if (!visited[j] && distance[j] < min_value) {
                min_value = distance[j];
                min_index = j;
            }
        }
        visited[min_index] = 1;

        for (j = 0; j < V; j++) {
            if (!visited[j] && adj[min_index][j] != INF && distance[min_index] + adj[min_index][j] < distance[j]) {
                distance[j] = distance[min_index] + adj[min_index][j];
            }
        }
    }

    printf("시작 노드로부터의 최단 거리:\n");
    for (i = 0; i < V; i++) {
        printf("%d에서 %d까지: %d\n", start, i, distance[i]);
    }
}

void DAG(void) {
    int close = 1;
    int i, j;

    printf("정점 개수: ");
    scanf_s("%d", &V);
    printf("간선 개수: ");
    scanf_s("%d", &E);

    initAdj2();

    printf("간선 정보(시작 노드 도착 노드 비용): \n");
    for (i = 0; i < E; i++) {
        int start, dest, cost;
        scanf_s("%d %d %d", &start, &dest, &cost);
        adj[start][dest] = cost;
    }

    printf("시작 노드를 입력하세요: ");
    int start_node;
    scanf_s("%d", &start_node);

    dijkstra2(start_node);

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

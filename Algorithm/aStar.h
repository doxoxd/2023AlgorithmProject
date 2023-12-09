#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

typedef struct Node9 {
    int city;
    int f;
    int g;
    int h;
    struct Node9* parent;
} Node9;

int** createGraph9(int n) {
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
    }
    return graph;
}

Node9* createNode9(int city, int f, int g, int h, Node9* parent) {
    Node9* newNode = (Node9*)malloc(sizeof(Node9));
    newNode->city = city;
    newNode->f = f;
    newNode->g = g;
    newNode->h = h;
    newNode->parent = parent;
    return newNode;
}

int heuristic(int city, int dest) {
    return 0; // 휴리스틱 함수, 여기서는 간단히 0으로 설정합니다.
}

void printPath9(Node9* current) {
    if (current == NULL) {
        return;
    }
    printPath9(current->parent);
    printf("%d ", current->city);
}

void astar(int** graph, int start, int dest, int n) {
    Node9* startNode = createNode9(start, 0, 0, 0, NULL);
    startNode->h = heuristic(start, dest);

    while (startNode != NULL) {
        if (startNode->city == dest) {
            printf("최단 경로: ");
            printPath9(startNode);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (graph[startNode->city][i] != 0) {
                int g = startNode->g + graph[startNode->city][i];
                int h = heuristic(i, dest);
                int f = g + h;
                Node9* newNode = createNode9(i, f, g, h, startNode);
                newNode->parent = startNode->parent; // 수정: 'next' 대신 'parent'로 수정
                startNode->parent = newNode; // 수정: 'next' 대신 'parent'로 수정
            }
        }

        startNode = startNode->parent;
    }

    printf("최단 경로가 존재하지 않습니다.\n");
}

void aStar(void) {
    int close = 1;
    int** graph;
    int numCities, start, dest;

    printf("도시의 수를 입력하세요 (최대 %d개): ", MAX_CITIES);
    scanf_s("%d", &numCities);

    graph = createGraph9(numCities);

    printf("도시 간의 거리를 입력하세요:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf_s("%d", &graph[i][j]);
        }
    }

    printf("출발 도시를 입력하세요 (0부터 %d까지): ", numCities - 1);
    scanf_s("%d", &start);
    printf("도착 도시를 입력하세요 (0부터 %d까지): ", numCities - 1);
    scanf_s("%d", &dest);

    astar(graph, start, dest, numCities);

    for (int i = 0; i < numCities; i++) {
        free(graph[i]);
    }
    free(graph);

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

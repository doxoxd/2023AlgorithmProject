#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES3 20


// 다익스트라 알고리즘
struct Node6 {
    int vertex;
    int weight;
    struct Node6* next;
};

struct Graph6 {
    int numVertices;
    struct Node6** adjLists;
};

struct Node6* createNode6(int v, int weight) {
    struct Node6* newNode = (struct Node6*)malloc(sizeof(struct Node6));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph6* createGraph6(int vertices) {
    struct Graph6* graph = (struct Graph6*)malloc(sizeof(struct Graph6));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node6**)malloc(vertices * sizeof(struct Node6*));
    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge6(struct Graph6* graph, int src, int dest, int weight) {
    struct Node6* newNode = createNode6(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printDijkstra(int dist[], int n) {
    printf("노드   최단 거리\n");
    for (int i = 0; i < n; ++i) {
        printf("%d     %d\n", i, dist[i]);
    }
}

int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(struct Graph6* graph, int src) {
    int V = graph->numVertices;
    int dist[20];
    int sptSet[20];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;

        struct Node6* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!sptSet[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }

    printDijkstra(dist, V);
}

void Dijkstra(void) {
    int close = 1;
    int vertices, edges, i;
    printf("노드의 수를 입력하세요: ");
    scanf_s("%d", &vertices);

    struct Graph6* graph = createGraph6(vertices);

    printf("간선의 수를 입력하세요: ");
    scanf_s("%d", &edges);

    for (i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("간선 %d (출발지 목적지 가중치): ", i + 1);
        scanf_s("%d %d %d", &src, &dest, &weight);
        addEdge6(graph, src, dest, weight);
    }

    int startVertex;
    printf("다익스트라 알고리즘을 적용할 시작 노드를 입력하세요: ");
    scanf_s("%d", &startVertex);

    printf("%d번 노드에서 시작하여 다른 모든 노드까지의 최단 경로:\n", startVertex);
    dijkstra(graph, startVertex);

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

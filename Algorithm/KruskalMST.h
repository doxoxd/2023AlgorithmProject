#pragma once
#include <stdio.h>
#include <stdlib.h>


//크루스칼 알고리즘
struct Edge {
    int src, dest, weight;
};

struct Graph5 {
    int numVertices, numEdges;
    struct Edge* edge;
};

struct Graph5* createGraph5(int vertices, int edges) {
    struct Graph5* graph = (struct Graph5*)malloc(sizeof(struct Graph5));
    graph->numVertices = vertices;
    graph->numEdges = edges;
    graph->edge = (struct Edge*)malloc(edges * sizeof(struct Edge));
    return graph;
}

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a, const void* b) {
    struct Edge* aEdge = (struct Edge*)a;
    struct Edge* bEdge = (struct Edge*)b;
    return aEdge->weight - bEdge->weight;
}

void kruskalMST(struct Graph5* graph) {
    int vertices = graph->numVertices;
    struct Edge result[20];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->numEdges, sizeof(graph->edge[0]), compare);

    struct Subset* subsets = (struct Subset*)malloc(vertices * sizeof(struct Subset));

    for (int v = 0; v < vertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < vertices - 1 && i < graph->numEdges) {
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("간선   가중치\n");
    for (i = 0; i < e; i++)
        printf("%d - %d    %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

void KruskalMST(void) {
    int close = 1;
    int vertices, edges, i;
    printf("노드의 수를 입력하세요: ");
    scanf_s("%d", &vertices);

    printf("간선의 수를 입력하세요: ");
    scanf_s("%d", &edges);

    struct Graph5* graph = createGraph5(vertices, edges);

    for (i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("간선 %d (출발지 목적지 가중치): ", i + 1);
        scanf_s("%d %d %d", &src, &dest, &weight);
        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = weight;
    }

    printf("크루스칼 알고리즘을 적용한 최소 신장 트리:\n");
    kruskalMST(graph);

    free(graph->edge);
    free(graph);

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

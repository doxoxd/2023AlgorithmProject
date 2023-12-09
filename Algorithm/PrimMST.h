#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES2 20

// ���� �˰���
struct Node4 {
    int vertex;
    int weight;
    struct Node4* next;
};

struct Graph4 {
    int numVertices;
    struct Node4** adjLists;
};

struct Node4* createNode(int v, int weight) {
    struct Node4* newNode = (struct Node4*)malloc(sizeof(struct Node4));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph4* createGraph4(int vertices) {
    struct Graph4* graph = (struct Graph4*)malloc(sizeof(struct Graph4));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node4**)malloc(vertices * sizeof(struct Node4*));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge4(struct Graph4* graph, int src, int dest, int weight) {
    // src���� dest�� ���� ����ġ�� weight�� ���� �߰�
    struct Node4* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // dest���� src�� ���� ����ġ�� weight�� ���� �߰� (������ �׷����� ���)
    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int minKey(int key[], int mstSet[], int numVertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int** graph, int numVertices) {
    printf("����   ����ġ\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(struct Graph4* graph, int numVertices) {
    int parent[20];
    int key[20];
    int mstSet[20];

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);
        mstSet[u] = 1;

        struct Node4* temp = graph->adjLists[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (mstSet[v] == 0 && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
            temp = temp->next;
        }
    }

    printMST(parent, graph->adjLists, numVertices);
}

void PrimMST(void) {
    int close = 1;
    int vertices, edges, i;
    printf("����� ���� �Է��ϼ���: ");
    scanf_s("%d", &vertices);

    struct Graph4* graph = createGraph4(vertices);

    printf("������ ���� �Է��ϼ���: ");
    scanf_s("%d", &edges);

    for (i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("���� %d (����� ������ ����ġ): ", i + 1);
        scanf_s("%d %d %d", &src, &dest, &weight);
        addEdge4(graph, src, dest, weight);
    }

    printf("���� �˰����� ������ �ּ� ���� Ʈ��:\n");
    primMST(graph, vertices);

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

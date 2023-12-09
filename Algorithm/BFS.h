#pragma once

// �ʺ� �켱 Ž��
#include <stdio.h>
#include <stdlib.h>

struct Node3 {
    int vertex;
    struct Node3* next;
};

struct Graph3 {
    int numVertices;
    struct Node3** adjLists;
    int* visited;
};

struct Graph3* createGraph3(int vertices) {
    struct Graph3* graph = (struct Graph3*)malloc(sizeof(struct Graph3));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node3**)malloc(vertices * sizeof(struct Node3*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // �湮 ���� �ʱ�ȭ (0: �湮 �� ��, 1: �湮 ��)
    }
    return graph;
}

void addEdge3(struct Graph3* graph, int src, int dest) {
    struct Node3* newNode = (struct Node3*)malloc(sizeof(struct Node3));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = (struct Node3*)malloc(sizeof(struct Node3));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void bfs(struct Graph3* graph, int startVertex) {
    int queue[100];
    int front = 0, rear = 0;

    graph->visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d�� ��带 �湮�߽��ϴ�.\n", currentVertex);

        struct Node3* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

void BFS(void) {
    int close = 1;
    int vertices, edges, i;
    printf("����� ���� �Է��ϼ���: ");
    scanf_s("%d", &vertices);

    struct Graph3* graph = createGraph3(vertices);

    printf("������ ���� �Է��ϼ���: ");
    scanf_s("%d", &edges);

    for (i = 0; i < edges; i++) {
        int src, dest;
        printf("���� %d (����� ������): ", i + 1);
        scanf_s("%d %d", &src, &dest);
        addEdge3(graph, src, dest);
    }

    int startVertex;
    printf("BFS�� ������ ���� ��带 �Է��ϼ���: ");
    scanf_s("%d", &startVertex);

    printf("%d�� ��忡�� �����ϴ� �ʺ� �켱 Ž��:\n", startVertex);
    bfs(graph, startVertex);

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

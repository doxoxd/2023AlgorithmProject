#include <stdio.h>
#include <stdlib.h>

// ���� �켱 Ž��
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // �湮 ���� �ʱ�ȭ (0: �湮 �� ��, 1: �湮 ��)
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void dfs(struct Graph* graph, int vertex) {
    struct Node* adjList = graph->adjLists[vertex];
    struct Node* temp = adjList;

    graph->visited[vertex] = 1; // ���� ��带 �湮 ������ ǥ��
    printf("%d�� ��带 �湮�߽��ϴ�.\n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0) {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}


void DFS(void) {
    int close = 1;
    int vertices, edges, i;
    printf("����� ���� �Է��ϼ���: ");
    scanf_s("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("������ ���� �Է��ϼ���: ");
    scanf_s("%d", &edges);

    for (i = 0; i < edges; i++) {
        int src, dest;
        printf("���� %d (����� ������): ", i + 1);
        scanf_s("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("DFS�� ������ ���� ��带 �Է��ϼ���: ");
    scanf_s("%d", &startVertex);

    printf("%d�� ��忡�� �����ϴ� ���� �켱 Ž��:\n", startVertex);
    dfs(graph, startVertex);

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}
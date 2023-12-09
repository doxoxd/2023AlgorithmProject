#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_V 10
#define MIN(a,b) a<b ? a:b
#define INF 987654321

// �÷��̵� ���� �˰���
int V, E;
int adj[MAX_V][MAX_V];
void initAdj() {
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++) {
            adj[i][j] = INF;
            if (i == j)adj[i][j] = 0;
        }
}
void floyd() {
    int k, j, i;

    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);
}


void Floyd(void) {
    int close = 1;
    int i, j;
    printf("���� ���� :");
    scanf_s("%d", &V);
    printf("���� ���� :");
    scanf_s("%d", &E);

    initAdj();

    printf("���� ����( ����1 ����2 ���) \n");
    for (i = 0; i < E; i++) {
        int v1, v2, cost;
        scanf_s("%d %d %d", &v1, &v2, &cost);
        adj[v1][v2] = adj[v2][v1] = cost;
    }


    floyd();

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++)
            printf("%d~%d������ �ִܰŸ�:%d\n", i, j, adj[i][j]);
        printf("\n\n");
    }

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

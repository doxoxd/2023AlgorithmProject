#pragma once
#include <stdio.h>

#define N 5 // 미로의 크기

int solution[N][N]; // 경로를 저장할 배열

void printSolution() {
    printf("미로의 경로:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int x, int y, int maze[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

int solveMazeUtil(int x, int y, int maze[N][N]) {
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return 1;
    }

    if (isSafe(x, y, maze)) {
        solution[x][y] = 1;

        if (solveMazeUtil(x + 1, y, maze))
            return 1;
        if (solveMazeUtil(x, y + 1, maze))
            return 1;

        solution[x][y] = 0;
        return 0;
    }

    return 0;
}

int solveMaze(int maze[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            solution[i][j] = 0;
        }
    }

    if (solveMazeUtil(0, 0, maze) == 0) {
        printf("경로가 존재하지 않습니다.\n");
        return 0;
    }

    printSolution();
    return 1;
}

void Backtracking(void) {
    int close = 1;
    int maze[N][N];

    printf("5*5 미로를 입력하세요(0: 길, 1: 벽):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf_s("%d", &maze[i][j]);
        }
    }

    solveMaze(maze);
    
    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

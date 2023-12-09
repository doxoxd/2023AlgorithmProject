#pragma once
#include <stdio.h>
#include <stdlib.h>

// 최소 함수
int min2(int a, int b) {
    return (a < b) ? a : b;
}

// 행렬 경로 문제 해결 함수
void find_min_path(int** matrix, int rows, int cols) {
    int** dp = (int**)malloc(rows * sizeof(int*)); // 동적 프로그래밍을 위한 배열 동적 할당

    // 행렬 dp 동적 할당 및 초기화
    for (int i = 0; i < rows; ++i) {
        dp[i] = (int*)malloc(cols * sizeof(int));
    }

    // 경로의 합 계산을 위한 동적 프로그래밍
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < rows; ++i) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0]; // 첫 번째 열의 값은 왼쪽에서 오는 값밖에 없음
    }
    for (int j = 1; j < cols; ++j) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j]; // 첫 번째 행의 값은 위에서 오는 값밖에 없음
    }
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            dp[i][j] = matrix[i][j] + min2(dp[i - 1][j], dp[i][j - 1]); // 왼쪽이나 위쪽에서 더 작은 값을 선택하여 더함
        }
    }

    // 최적 경로 역추적
    int i = rows - 1, j = cols - 1;
    printf("최적 경로: ");
    while (i > 0 || j > 0) {
        printf("(%d, %d) -> ", i, j);
        if (i == 0) {
            j--;
        }
        else if (j == 0) {
            i--;
        }
        else {
            if (dp[i - 1][j] < dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    printf("(0, 0)\n");
    printf("최적 경로의 합: %d\n", dp[rows - 1][cols - 1]);

    // 동적 할당 해제
    for (int i = 0; i < rows; ++i) {
        free(dp[i]);
    }
    free(dp);
}

// 메인 함수
void FindPath(void) {
    int close = 1;
    int rows, cols;
    printf("행의 개수를 입력하세요: ");
    scanf_s("%d", &rows);
    printf("열의 개수를 입력하세요: ");
    scanf_s("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*)); // 행렬 동적 할당

    printf("%d x %d 행렬의 각 요소를 입력하세요:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; ++j) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    find_min_path(matrix, rows, cols);

    // 동적 할당 해제
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}


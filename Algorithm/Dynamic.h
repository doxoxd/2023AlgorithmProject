#pragma once
#include <stdio.h>
#include <stdlib.h>

// �ּ� �Լ�
int min2(int a, int b) {
    return (a < b) ? a : b;
}

// ��� ��� ���� �ذ� �Լ�
void find_min_path(int** matrix, int rows, int cols) {
    int** dp = (int**)malloc(rows * sizeof(int*)); // ���� ���α׷����� ���� �迭 ���� �Ҵ�

    // ��� dp ���� �Ҵ� �� �ʱ�ȭ
    for (int i = 0; i < rows; ++i) {
        dp[i] = (int*)malloc(cols * sizeof(int));
    }

    // ����� �� ����� ���� ���� ���α׷���
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < rows; ++i) {
        dp[i][0] = dp[i - 1][0] + matrix[i][0]; // ù ��° ���� ���� ���ʿ��� ���� ���ۿ� ����
    }
    for (int j = 1; j < cols; ++j) {
        dp[0][j] = dp[0][j - 1] + matrix[0][j]; // ù ��° ���� ���� ������ ���� ���ۿ� ����
    }
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            dp[i][j] = matrix[i][j] + min2(dp[i - 1][j], dp[i][j - 1]); // �����̳� ���ʿ��� �� ���� ���� �����Ͽ� ����
        }
    }

    // ���� ��� ������
    int i = rows - 1, j = cols - 1;
    printf("���� ���: ");
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
    printf("���� ����� ��: %d\n", dp[rows - 1][cols - 1]);

    // ���� �Ҵ� ����
    for (int i = 0; i < rows; ++i) {
        free(dp[i]);
    }
    free(dp);
}

// ���� �Լ�
void FindPath(void) {
    int close = 1;
    int rows, cols;
    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &rows);
    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*)); // ��� ���� �Ҵ�

    printf("%d x %d ����� �� ��Ҹ� �Է��ϼ���:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; ++j) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    find_min_path(matrix, rows, cols);

    // ���� �Ҵ� ����
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}


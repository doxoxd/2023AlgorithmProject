#pragma once
#include <stdio.h>
#include <stdlib.h>

// 집합을 표현할 트리 노드 구조체 정의
struct Node8 {
    int data;
    struct Node8* parent;
};

// 노드 생성 함수
struct Node8* make_set(int x) {
    struct Node8* new_node = (struct Node8*)malloc(sizeof(struct Node8));
    new_node->data = x;
    new_node->parent = new_node;  // 처음에는 자신이 집합의 대표
    return new_node;
}

// 집합의 대표 노드를 찾는 함수
struct Node8* find_set(struct Node8* node) {
    if (node != node->parent) {
        node->parent = find_set(node->parent);  // 경로 압축
    }
    return node->parent;
}

// 두 집합을 합치는 함수
void union_sets(struct Node8* x, struct Node8* y) {
    struct Node8* x_rep = find_set(x);
    struct Node8* y_rep = find_set(y);
    if (x_rep != y_rep) {
        y_rep->parent = x_rep;  // 한 집합의 대표를 다른 집합의 대표의 자식으로 설정
    }
}

// 집합 출력 함수 (대표 노드만 출력)
void print_sets(struct Node8* nodes[], int n) {
    printf("각 집합의 대표 노드:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d -> %d\n", nodes[i]->data, find_set(nodes[i])->data);
    }
}

// 메모리 해제 함수
void free_memory(struct Node8* nodes[], int n) {
    for (int i = 0; i < n; ++i) {
        free(nodes[i]);
    }
}

// 메인 함수
void TreeSet(void) {
    int close = 1;
    int num_elements;
    printf("집합의 크기를 입력하세요: ");
    scanf_s("%d", &num_elements);

    struct Node8* nodes[20];

    printf("%d개의 원소를 입력하세요:\n", num_elements);
    for (int i = 0; i < num_elements; ++i) {
        int x;
        scanf_s("%d", &x);
        nodes[i] = make_set(x);
    }

    print_sets(nodes, num_elements);  // 각 집합의 대표 출력

    int choice, x, y;
    printf("\n1. 두 집합 합치기\n2. 종료\n");
    while (1) {
        printf("\n연산 선택: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            printf("합칠 두 원소를 선택하세요: ");
            scanf_s("%d %d", &x, &y);
            union_sets(nodes[x - 1], nodes[y - 1]);
            printf("합친 후의 각 집합의 대표 출력:\n");
            print_sets(nodes, num_elements);
        }
        else if (choice == 2) {
            break;
        }
        else {
            printf("올바른 선택이 아닙니다. 다시 선택하세요.\n");
        }
    }

    // 메모리 해제
    free_memory(nodes, num_elements);

    printf("\n닫기(0 입력) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

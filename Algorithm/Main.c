#include <stdio.h>
#include <stdlib.h> 
#include "Sort.h"
#include "Hash_Div.h"
#include "Hash_Mul.h"
#include "DFS.h"
#include "BFS.h"
#include "PrimMST.h"
#include "KruskalMST.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "Floyd.h"
#include "DAG.h"
#include "LinkedSet.h"
#include "TreeSet.h"
#include "Dynamic.h"
#include "StateSpaceTree.h"
#include "Backtracking.h"
#include "Prunning.h"
#include "aStar.h"
#include "TreeSearch.h"
#include "RedBlackTree.h"
#include "BTree.h"
#include "KDTree.h"
#include "KDBTree.h"
#include "RTree.h"

#define _CRT_SECURE_NO_WARNINGS 
#define ALG_INDEX 8
#define SORT_INDEX 8
#define TREE_INDEX 6
#define HASH_INDEX 2
#define SET_INDEX 2
#define DYN_INDEX 1
#define GRAPH_INDEX 9
#define TREE2_INDEX 4


typedef struct Menu {   // 메뉴 이름,메뉴 가격,메뉴 수량을 저장하기 위해 구조체 Menu 정의. typedef을 사용하여 struct Menu --> Menu
	char* Name;   // 메뉴 이름(문자열)을 가리키는 포인터 변수 선언
}Menu;

//Menu Algorithm[ALG_INDEX] = { {"1) 정렬"}, {"2) 검색트리"}, {"3) 해시 테이블"}, {"4) 집합의 처리"}, {"5) 동적 프로그래밍"}, {"6) 그래프"}, {"7) 상태 공간 트리의 탐색"}, {"8) 종료"} };
Menu Sort[SORT_INDEX] = { {"100) 선택 정렬"}, {"101) 버블 정렬"}, {"102) 삽입 정렬"}, {"103) 병합 정렬"}, {"104) 퀵 정렬"}, {"105) 힙 정렬"}, {"106) 기수 정렬"}, {"107) 계수 정렬"} };
Menu Tree[TREE_INDEX] = { {"200) 이진 검색 트리"}, {"201) 레드 블랙 트리"}, {"202) B-트리"}, {"203) KD-트리"}, {"204) KDB-트리"}, {"205) R-트리"} };
Menu Hash[HASH_INDEX] = { {"300) 해시 함수-나누기"}, {"301) 해시 함수-곱하기"} };
Menu Set[SET_INDEX] = { {"400) 연결 리스트를 이용한 집합의 처리"}, {"401) 트리를 이용한 집합의 처리"} };
Menu Dynamic[DYN_INDEX] = { {"500) 행렬 경로 문제"} };
Menu Graphs[GRAPH_INDEX] = { {"600) 너비 우선 탐색"}, {"601) 깊이 우선 탐색"}, {"602) 프림 알고리즘"}, {"603) 크루스칼 알고리즘"}, {"604) 위상정렬"}
, {"605) 다익스트라 알고리즘"}, {"606) 벨만-포드 알고리즘"}, {"607) 모든 쌍 최단 경로 알고리즘"}, {"608) 사이클 없는 그래프의 최단 경로"} };
Menu Tree2[TREE2_INDEX] = { {"700) 상태 공간 트리"}, {"701) 백트래킹"}, {"702) 한정 분기"}, {"703) A* 알고리즘"} };


int menu_display(void);
void order(void);
void load_Algorithm(int n);

int main(void) {
	int c;

	while ((c = menu_display()) != 0) {
		switch (c) {
		case 1: order(); break;
		default: break;
		}
	}
	printf("\n");

	return 0;
}

int menu_display() {
	Menu* m = NULL;        // Menu형 구조체 배열을 가리킬 포인터 변수 m을 NULL로 초기화
	int select = 0;        // 번호를 0으로 초기화

	system("cls");         // 함수가 실행될 때마다 메뉴 목록을 보기 좋게 출력하기 위해 콘솔창에 있는 항목을 다 지워주는 함수
	printf("\n=================================================== 알고리즘 ==================================================\n\n");


	m = Sort;       
	printf("\n- 정렬 -\n");
	for (int i = 0; i < SORT_INDEX; i++) {   // BREAD_INDEX만큼 반복
		printf("%-20s\t", (m + i)->Name);   // 포인터 변수 m이 가리키는 곳의 menuName, menuPrice 출력

		if ((i + 1) % 5 == 0)                                          // 한 줄당 4개의 메뉴만 출력하기 위한 조건
			printf("\n");
	}
	printf("\n\n");

	m = Tree;       
	printf("\n- 검색 트리 -\n");
	for (int i = 0; i < TREE_INDEX; i++) {  
		printf("%-20s\t", (m + i)->Name);  

		if ((i + 1) % 5 == 0)                                          
			printf("\n");
	}
	printf("\n\n");

	m = Hash;
	printf("\n- 해시 테이블 -\n");
	for (int i = 0; i < HASH_INDEX; i++) {
		printf("%-20s\t", (m + i)->Name);

		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n\n");

	m = Set;
	printf("\n- 집합의 처리 -\n");
	for (int i = 0; i < SET_INDEX; i++) {
		printf("%-20s\t", (m + i)->Name);

		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n\n");

	m = Dynamic;
	printf("\n- 동적 프로그래밍 -\n");
	for (int i = 0; i < DYN_INDEX; i++) {
		printf("%-20s\t", (m + i)->Name);

		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n\n");

	m = Graphs;
	printf("\n- 그래프 -\n");
	for (int i = 0; i < GRAPH_INDEX; i++) {
		printf("%-30s\t", (m + i)->Name);

		if ((i + 1) % 3 == 0)
			printf("\n");
	}
	printf("\n\n");

	m = Tree2;
	printf("\n- 상태 공간 트리의 탐색 -\n");
	for (int i = 0; i < TREE2_INDEX; i++) {
		printf("%-20s\t", (m + i)->Name);

		if ((i + 1) % 4 == 0)
			printf("\n");
	}
	printf("\n\n");

	printf("\n0.프로그램 종료   1. 알고리즘 선택\n\n");
	printf("번호 선택 후 Enter >> ");
	scanf_s("%d", &select);                   // 번호 선택

	return select;                            // 선택한 번호 반환
}

void order(void) {   // 1. 추가 를 눌렀을 때 작동하는 함수 정의
	int num = 0;    // 메뉴 번호를 0으로 초기화
	int count = 0;  // 수량을 0으로 초기화

	printf("번호 입력후 Enter(0: cancel) >> ");
	scanf_s("%d", &num);      // 메뉴 번호 입력

	if (num == 0)	// num이 0이라면?
		return;		//main 으로 돌아감

	load_Algorithm(num);
}

void load_Algorithm(int n) {
	Menu* p = NULL;

	int number = n;							// n을 number에 저장
	int digit = 0;							// n의 자릿수를 계산하기 위한 변수 digit을 0으로 초기화
	char str_number[4] = { 0 };				// number를 문자열로 바꿔서 저장할 배열을 0으로 초기화


	for (int i = 10; n > 0; digit++)		// n의 자릿수 계산
		n = n / i;
	if (digit != 3)							// main 으로 돌아감(메뉴 번호는 다 세자리 수이기 때문)
		return;

	sprintf(str_number, "%d", number);		// 정수 number를 str_number에 문자열 형태로 저장

	// 정렬
	if (strncmp(str_number, "1", 1) == 0) {		// 문자열 str_number와 문자열 "1"의 첫글자가 같다면?
		p = Sort;									// 포인터 변수 p가 구조체 배열 Sort의 주소를 가리킴
		for (int i = 0; i < SORT_INDEX; i++) {				// SORT_INDEX만큼 반복
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p가 가리키는 곳의 Name과 문자열 str_number의 첫 세글자가 같다면?
				if (strncmp(str_number, "100", 3) == 0) { SelctionSort(); break; }			// 선택 정렬
				else if (strncmp(str_number, "101", 3) == 0) { BubbleSort(); break; }		// 버블 정렬
				else if (strncmp(str_number, "102", 3) == 0) { InsertionSort(); break; }	// 삽입 정렬
				else if (strncmp(str_number, "103", 3) == 0) { MergeSort(); break; }		// 병합 정렬
				else if (strncmp(str_number, "104", 3) == 0) { QuickSort(); break; }		// 퀵 정렬
				else if (strncmp(str_number, "105", 3) == 0) { HeapSort(); break; }			// 힙 정렬
				else if (strncmp(str_number, "106", 3) == 0) { RadixSort(); break; }		// 기수 정렬
				else if (strncmp(str_number, "107", 3) == 0) { CointingSort(); break; }		// 계수 정렬
				break;
			}
		}
	}

	// 검색 트리
	else if (strncmp(str_number, "2", 1) == 0) {		// 문자열 str_number와 문자열 "1"의 첫글자가 같다면?
		p = Tree;
		for (int i = 0; i < TREE_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p가 가리키는 곳의 Name과 문자열 str_number의 첫 세글자가 같다면?
				if (strncmp(str_number, "200", 3) == 0) { TreeSearch(); break; }			// 이진 검색 트리
				else if (strncmp(str_number, "201", 3) == 0) { RedBlackTree(); break; }		// 레드 블랙 트리
				else if (strncmp(str_number, "202", 3) == 0) { BTree(); break; }			// B-트리
				else if (strncmp(str_number, "203", 3) == 0) { KDTree(); break; }		// KD-트리
				else if (strncmp(str_number, "204", 3) == 0) { KDBTree(); break; }		// KDB-트리
				else if (strncmp(str_number, "205", 3) == 0) { RTree(); break; }			// R-트리
				break;
			}
		}
	}

	// 해시 테이블
	else if (strncmp(str_number, "3", 1) == 0) {		// 문자열 str_number와 문자열 "1"의 첫글자가 같다면?
		p = Hash;								
		for (int i = 0; i < HASH_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p가 가리키는 곳의 Name과 문자열 str_number의 첫 세글자가 같다면?
				if (strncmp(str_number, "300", 3) == 0) { Hash_Div(); break; }				// 해시 함수 - 나누기
				else if (strncmp(str_number, "301", 3) == 0) { Hash_Mul();  break; }		// 해시 함수 - 곱하기
				break;
			}
		}
	}

	// 집합의 처리
	else if (strncmp(str_number, "4", 1) == 0) {		// 문자열 str_number와 문자열 "1"의 첫글자가 같다면?
		p = Set;
		for (int i = 0; i < SET_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p가 가리키는 곳의 Name과 문자열 str_number의 첫 세글자가 같다면?
				if (strncmp(str_number, "400", 3) == 0) { LinkedSet(); break; }	// 연결 리스트 이용
				else if (strncmp(str_number, "401", 3) == 0) { TreeSet(); break; }		// 트리 이용
				break;
			}
		}
	}

	// 동적 프로그래밍
	else if (strncmp(str_number, "5", 1) == 0) {		// 문자열 str_number와 문자열 "1"의 첫글자가 같다면?
		p = Dynamic;
		for (int i = 0; i < DYN_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p가 가리키는 곳의 Name과 문자열 str_number의 첫 세글자가 같다면?
				if (strncmp(str_number, "500", 3) == 0) { FindPath(); break; }	// 행렬 경로 문제
				break;
			}
		}
	}

	// 그래프
	else if (strncmp(str_number, "6", 1) == 0) {		// 문자열 str_number와 문자열 "1"의 첫글자가 같다면?
		p = Graphs;
		for (int i = 0; i < GRAPH_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p가 가리키는 곳의 Name과 문자열 str_number의 첫 세글자가 같다면?
				if (strncmp(str_number, "600", 3) == 0) { BFS(); break; }					// 너비 우선 탐색
				else if (strncmp(str_number, "601", 3) == 0) { DFS(); break; }				// 깊이 우선 탐색
				else if (strncmp(str_number, "602", 3) == 0) { PrimMST(); break; }			// 프림 알고리즘
				else if (strncmp(str_number, "603", 3) == 0) { KruskalMST(); break; }		// 크루스칼 알고리즘
				else if (strncmp(str_number, "604", 3) == 0) { TopologicalSort(); break; }	// 위상 정렬
				else if (strncmp(str_number, "605", 3) == 0) { Dijkstra(); break; }			// 다익스트라 알고리즘
				else if (strncmp(str_number, "606", 3) == 0) { BellmanFord(); break; }		// 벨만-포드 알고리즘
				else if (strncmp(str_number, "607", 3) == 0) { Floyd(); break; }			// 모든 쌍 최단 경로 알고리즘
				else if (strncmp(str_number, "608", 3) == 0) { DAG(); break; }					// 사이클 없는 그래프의 최단 경로
				break;
			}
		}
	}

	// 상태 공간 트리의 탐색
	else if (strncmp(str_number, "7", 1) == 0) {		// 문자열 str_number와 문자열 "1"의 첫글자가 같다면?
		p = Tree2;
		for (int i = 0; i < TREE2_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p가 가리키는 곳의 Name과 문자열 str_number의 첫 세글자가 같다면?
				if (strncmp(str_number, "700", 3) == 0) { StateSpaceTree(); break; }		// 상태 공간 트리
				else if (strncmp(str_number, "701", 3) == 0) { Backtracking(); break; }		// 백트랙킹
				else if (strncmp(str_number, "702", 3) == 0) { Prunning(); break; }			// 한정 분기
				else if (strncmp(str_number, "703", 3) == 0) { aStar(); break; }			// A* 알고리즘
				break;
			}
		}
	}
}
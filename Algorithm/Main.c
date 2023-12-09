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


typedef struct Menu {   // �޴� �̸�,�޴� ����,�޴� ������ �����ϱ� ���� ����ü Menu ����. typedef�� ����Ͽ� struct Menu --> Menu
	char* Name;   // �޴� �̸�(���ڿ�)�� ����Ű�� ������ ���� ����
}Menu;

//Menu Algorithm[ALG_INDEX] = { {"1) ����"}, {"2) �˻�Ʈ��"}, {"3) �ؽ� ���̺�"}, {"4) ������ ó��"}, {"5) ���� ���α׷���"}, {"6) �׷���"}, {"7) ���� ���� Ʈ���� Ž��"}, {"8) ����"} };
Menu Sort[SORT_INDEX] = { {"100) ���� ����"}, {"101) ���� ����"}, {"102) ���� ����"}, {"103) ���� ����"}, {"104) �� ����"}, {"105) �� ����"}, {"106) ��� ����"}, {"107) ��� ����"} };
Menu Tree[TREE_INDEX] = { {"200) ���� �˻� Ʈ��"}, {"201) ���� �� Ʈ��"}, {"202) B-Ʈ��"}, {"203) KD-Ʈ��"}, {"204) KDB-Ʈ��"}, {"205) R-Ʈ��"} };
Menu Hash[HASH_INDEX] = { {"300) �ؽ� �Լ�-������"}, {"301) �ؽ� �Լ�-���ϱ�"} };
Menu Set[SET_INDEX] = { {"400) ���� ����Ʈ�� �̿��� ������ ó��"}, {"401) Ʈ���� �̿��� ������ ó��"} };
Menu Dynamic[DYN_INDEX] = { {"500) ��� ��� ����"} };
Menu Graphs[GRAPH_INDEX] = { {"600) �ʺ� �켱 Ž��"}, {"601) ���� �켱 Ž��"}, {"602) ���� �˰���"}, {"603) ũ�罺Į �˰���"}, {"604) ��������"}
, {"605) ���ͽ�Ʈ�� �˰���"}, {"606) ����-���� �˰���"}, {"607) ��� �� �ִ� ��� �˰���"}, {"608) ����Ŭ ���� �׷����� �ִ� ���"} };
Menu Tree2[TREE2_INDEX] = { {"700) ���� ���� Ʈ��"}, {"701) ��Ʈ��ŷ"}, {"702) ���� �б�"}, {"703) A* �˰���"} };


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
	Menu* m = NULL;        // Menu�� ����ü �迭�� ����ų ������ ���� m�� NULL�� �ʱ�ȭ
	int select = 0;        // ��ȣ�� 0���� �ʱ�ȭ

	system("cls");         // �Լ��� ����� ������ �޴� ����� ���� ���� ����ϱ� ���� �ܼ�â�� �ִ� �׸��� �� �����ִ� �Լ�
	printf("\n=================================================== �˰��� ==================================================\n\n");


	m = Sort;       
	printf("\n- ���� -\n");
	for (int i = 0; i < SORT_INDEX; i++) {   // BREAD_INDEX��ŭ �ݺ�
		printf("%-20s\t", (m + i)->Name);   // ������ ���� m�� ����Ű�� ���� menuName, menuPrice ���

		if ((i + 1) % 5 == 0)                                          // �� �ٴ� 4���� �޴��� ����ϱ� ���� ����
			printf("\n");
	}
	printf("\n\n");

	m = Tree;       
	printf("\n- �˻� Ʈ�� -\n");
	for (int i = 0; i < TREE_INDEX; i++) {  
		printf("%-20s\t", (m + i)->Name);  

		if ((i + 1) % 5 == 0)                                          
			printf("\n");
	}
	printf("\n\n");

	m = Hash;
	printf("\n- �ؽ� ���̺� -\n");
	for (int i = 0; i < HASH_INDEX; i++) {
		printf("%-20s\t", (m + i)->Name);

		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n\n");

	m = Set;
	printf("\n- ������ ó�� -\n");
	for (int i = 0; i < SET_INDEX; i++) {
		printf("%-20s\t", (m + i)->Name);

		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n\n");

	m = Dynamic;
	printf("\n- ���� ���α׷��� -\n");
	for (int i = 0; i < DYN_INDEX; i++) {
		printf("%-20s\t", (m + i)->Name);

		if ((i + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n\n");

	m = Graphs;
	printf("\n- �׷��� -\n");
	for (int i = 0; i < GRAPH_INDEX; i++) {
		printf("%-30s\t", (m + i)->Name);

		if ((i + 1) % 3 == 0)
			printf("\n");
	}
	printf("\n\n");

	m = Tree2;
	printf("\n- ���� ���� Ʈ���� Ž�� -\n");
	for (int i = 0; i < TREE2_INDEX; i++) {
		printf("%-20s\t", (m + i)->Name);

		if ((i + 1) % 4 == 0)
			printf("\n");
	}
	printf("\n\n");

	printf("\n0.���α׷� ����   1. �˰��� ����\n\n");
	printf("��ȣ ���� �� Enter >> ");
	scanf_s("%d", &select);                   // ��ȣ ����

	return select;                            // ������ ��ȣ ��ȯ
}

void order(void) {   // 1. �߰� �� ������ �� �۵��ϴ� �Լ� ����
	int num = 0;    // �޴� ��ȣ�� 0���� �ʱ�ȭ
	int count = 0;  // ������ 0���� �ʱ�ȭ

	printf("��ȣ �Է��� Enter(0: cancel) >> ");
	scanf_s("%d", &num);      // �޴� ��ȣ �Է�

	if (num == 0)	// num�� 0�̶��?
		return;		//main ���� ���ư�

	load_Algorithm(num);
}

void load_Algorithm(int n) {
	Menu* p = NULL;

	int number = n;							// n�� number�� ����
	int digit = 0;							// n�� �ڸ����� ����ϱ� ���� ���� digit�� 0���� �ʱ�ȭ
	char str_number[4] = { 0 };				// number�� ���ڿ��� �ٲ㼭 ������ �迭�� 0���� �ʱ�ȭ


	for (int i = 10; n > 0; digit++)		// n�� �ڸ��� ���
		n = n / i;
	if (digit != 3)							// main ���� ���ư�(�޴� ��ȣ�� �� ���ڸ� ���̱� ����)
		return;

	sprintf(str_number, "%d", number);		// ���� number�� str_number�� ���ڿ� ���·� ����

	// ����
	if (strncmp(str_number, "1", 1) == 0) {		// ���ڿ� str_number�� ���ڿ� "1"�� ù���ڰ� ���ٸ�?
		p = Sort;									// ������ ���� p�� ����ü �迭 Sort�� �ּҸ� ����Ŵ
		for (int i = 0; i < SORT_INDEX; i++) {				// SORT_INDEX��ŭ �ݺ�
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p�� ����Ű�� ���� Name�� ���ڿ� str_number�� ù �����ڰ� ���ٸ�?
				if (strncmp(str_number, "100", 3) == 0) { SelctionSort(); break; }			// ���� ����
				else if (strncmp(str_number, "101", 3) == 0) { BubbleSort(); break; }		// ���� ����
				else if (strncmp(str_number, "102", 3) == 0) { InsertionSort(); break; }	// ���� ����
				else if (strncmp(str_number, "103", 3) == 0) { MergeSort(); break; }		// ���� ����
				else if (strncmp(str_number, "104", 3) == 0) { QuickSort(); break; }		// �� ����
				else if (strncmp(str_number, "105", 3) == 0) { HeapSort(); break; }			// �� ����
				else if (strncmp(str_number, "106", 3) == 0) { RadixSort(); break; }		// ��� ����
				else if (strncmp(str_number, "107", 3) == 0) { CointingSort(); break; }		// ��� ����
				break;
			}
		}
	}

	// �˻� Ʈ��
	else if (strncmp(str_number, "2", 1) == 0) {		// ���ڿ� str_number�� ���ڿ� "1"�� ù���ڰ� ���ٸ�?
		p = Tree;
		for (int i = 0; i < TREE_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p�� ����Ű�� ���� Name�� ���ڿ� str_number�� ù �����ڰ� ���ٸ�?
				if (strncmp(str_number, "200", 3) == 0) { TreeSearch(); break; }			// ���� �˻� Ʈ��
				else if (strncmp(str_number, "201", 3) == 0) { RedBlackTree(); break; }		// ���� �� Ʈ��
				else if (strncmp(str_number, "202", 3) == 0) { BTree(); break; }			// B-Ʈ��
				else if (strncmp(str_number, "203", 3) == 0) { KDTree(); break; }		// KD-Ʈ��
				else if (strncmp(str_number, "204", 3) == 0) { KDBTree(); break; }		// KDB-Ʈ��
				else if (strncmp(str_number, "205", 3) == 0) { RTree(); break; }			// R-Ʈ��
				break;
			}
		}
	}

	// �ؽ� ���̺�
	else if (strncmp(str_number, "3", 1) == 0) {		// ���ڿ� str_number�� ���ڿ� "1"�� ù���ڰ� ���ٸ�?
		p = Hash;								
		for (int i = 0; i < HASH_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p�� ����Ű�� ���� Name�� ���ڿ� str_number�� ù �����ڰ� ���ٸ�?
				if (strncmp(str_number, "300", 3) == 0) { Hash_Div(); break; }				// �ؽ� �Լ� - ������
				else if (strncmp(str_number, "301", 3) == 0) { Hash_Mul();  break; }		// �ؽ� �Լ� - ���ϱ�
				break;
			}
		}
	}

	// ������ ó��
	else if (strncmp(str_number, "4", 1) == 0) {		// ���ڿ� str_number�� ���ڿ� "1"�� ù���ڰ� ���ٸ�?
		p = Set;
		for (int i = 0; i < SET_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p�� ����Ű�� ���� Name�� ���ڿ� str_number�� ù �����ڰ� ���ٸ�?
				if (strncmp(str_number, "400", 3) == 0) { LinkedSet(); break; }	// ���� ����Ʈ �̿�
				else if (strncmp(str_number, "401", 3) == 0) { TreeSet(); break; }		// Ʈ�� �̿�
				break;
			}
		}
	}

	// ���� ���α׷���
	else if (strncmp(str_number, "5", 1) == 0) {		// ���ڿ� str_number�� ���ڿ� "1"�� ù���ڰ� ���ٸ�?
		p = Dynamic;
		for (int i = 0; i < DYN_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p�� ����Ű�� ���� Name�� ���ڿ� str_number�� ù �����ڰ� ���ٸ�?
				if (strncmp(str_number, "500", 3) == 0) { FindPath(); break; }	// ��� ��� ����
				break;
			}
		}
	}

	// �׷���
	else if (strncmp(str_number, "6", 1) == 0) {		// ���ڿ� str_number�� ���ڿ� "1"�� ù���ڰ� ���ٸ�?
		p = Graphs;
		for (int i = 0; i < GRAPH_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p�� ����Ű�� ���� Name�� ���ڿ� str_number�� ù �����ڰ� ���ٸ�?
				if (strncmp(str_number, "600", 3) == 0) { BFS(); break; }					// �ʺ� �켱 Ž��
				else if (strncmp(str_number, "601", 3) == 0) { DFS(); break; }				// ���� �켱 Ž��
				else if (strncmp(str_number, "602", 3) == 0) { PrimMST(); break; }			// ���� �˰���
				else if (strncmp(str_number, "603", 3) == 0) { KruskalMST(); break; }		// ũ�罺Į �˰���
				else if (strncmp(str_number, "604", 3) == 0) { TopologicalSort(); break; }	// ���� ����
				else if (strncmp(str_number, "605", 3) == 0) { Dijkstra(); break; }			// ���ͽ�Ʈ�� �˰���
				else if (strncmp(str_number, "606", 3) == 0) { BellmanFord(); break; }		// ����-���� �˰���
				else if (strncmp(str_number, "607", 3) == 0) { Floyd(); break; }			// ��� �� �ִ� ��� �˰���
				else if (strncmp(str_number, "608", 3) == 0) { DAG(); break; }					// ����Ŭ ���� �׷����� �ִ� ���
				break;
			}
		}
	}

	// ���� ���� Ʈ���� Ž��
	else if (strncmp(str_number, "7", 1) == 0) {		// ���ڿ� str_number�� ���ڿ� "1"�� ù���ڰ� ���ٸ�?
		p = Tree2;
		for (int i = 0; i < TREE2_INDEX; i++) {
			if (strncmp(str_number, (p + i)->Name, 3) == 0) {			// p�� ����Ű�� ���� Name�� ���ڿ� str_number�� ù �����ڰ� ���ٸ�?
				if (strncmp(str_number, "700", 3) == 0) { StateSpaceTree(); break; }		// ���� ���� Ʈ��
				else if (strncmp(str_number, "701", 3) == 0) { Backtracking(); break; }		// ��Ʈ��ŷ
				else if (strncmp(str_number, "702", 3) == 0) { Prunning(); break; }			// ���� �б�
				else if (strncmp(str_number, "703", 3) == 0) { aStar(); break; }			// A* �˰���
				break;
			}
		}
	}
}
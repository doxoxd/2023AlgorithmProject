#pragma once
#include <stdio.h>
#define MAX 100
#define RADIX 10
#define DIGIT 2

// 선택 정렬
void SelctionSort() {
	int n;
	int list[100];
	int min, tmp;
	int close = 1;

	printf("정렬할 개수 >> "); scanf_s("%d", &n);
	printf("정렬할 원소 입력(%d개, 띄어쓰기로 구분) >> ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &list[i]);
	}
	printf("\n[선택 정렬 수행]\n");

	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (list[j] < list[min]) min = j;
		}
		tmp = list[i];
		list[i] = list[min];
		list[min] = tmp;
		printf("\n%d단계 : ", i + 1);
		for (int t = 0; t < n; t++) printf("%3d ", list[t]);
	}
	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}

// 버블 정렬
void BubbleSort(void) {
	int n = 0;
	int list[100];
	int tmp;
	int close = 1;


	printf("정렬할 개수 >> "); scanf_s("%d", &n);
	printf("정렬할 원소 입력(%d개, 띄어쓰기로 구분) >> ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &list[i]);
	}
	printf("\n[버블 정렬 수행]\n");

	for (int i = n - 1; i > 0; i--) {
		printf("\n %d단계>>", n - i);
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
			printf("\n\t");
			for (int t = 0; t < n; t++) printf("%3d", list[t]);
		}
	}
	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}

// 삽입 정렬
void InsertionSort(void) {
	int n = 0;
	int list[100];
	int close = 1;

	printf("정렬할 개수 >> "); scanf_s("%d", &n);
	printf("정렬할 원소 입력(%d개, 띄어쓰기로 구분) >> ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &list[i]);
	}

	printf("\n[삽입 정렬 수행]\n");

	for (int i = 1; i < n; i++) {
		int tmp = list[i];
		int j = i;
		while ((j > 0) && (list[j - 1] > tmp)) {
			list[j] = list[j - 1];
			j = j - 1;
		}
		list[j] = tmp;
		printf("\n %d단계 : ", i);
		for (int t = 0; t < n; t++) printf("%3d ", list[t]);
	}
	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}


// 병합 정렬
int sorted[MAX];
void merge(int a[], int m, int middle, int n, int size) {

	int i, j, k, t;
	i = m;
	j = middle + 1;
	k = m;

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k++] = a[i++];
		}
		else
			sorted[k++] = a[j++];
	}

	if (i > middle)
		for (t = j; t <= n; t++, k++) sorted[k] = a[t];
	else
		for (t = i; t <= middle; t++, k++) sorted[k] = a[t];

	for (t = m; t <= n; t++) a[t] = sorted[t];

	printf("\n 병합 정렬 >> ");
	for (t = 0; t <= size-1; t++) printf("%3d ", a[t]);
}
void mergeSort(int a[], int m, int n, int size) {
	int middle;
	if (m < n) {
		middle = (m + n) / 2;
		mergeSort(a, m, middle, size);
		mergeSort(a, middle + 1, n, size);
		merge(a, m, middle, n, size);
	}
}
void MergeSort(void) {
	int size;
	int a[100];
	int close = 1;

	printf("정렬할 개수 >> "); scanf_s("%d", &size);
	printf("정렬할 원소 입력(%d개, 띄어쓰기로 구분) >> ", size);
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &a[i]);
	}
	printf("\n[병합 정렬 수행]\n");
	mergeSort(a, 0, size - 1, size);
	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}


// 퀵 정렬
int counter = 0;
int partition(int a[], int begin, int end, int size) {
	int L = begin;
	int R = end;
	int pivot = (begin + end) / 2;
	printf("\n [ %d단계 : pivot = %d ] \n", ++counter, a[pivot]);
	while (L < R) {
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R]) >= a[pivot] && (L < R)) R--;
		if (L < R) {
			int tmp = a[L];
			a[L] = a[R];
			a[R] = tmp;

			if (L == pivot) pivot = R;
		}
	}

	int tmp = a[pivot];
	a[pivot] = a[R];
	a[R] = tmp;
	for (int t = 0; t < size; t++) printf("%4d", a[t]);
	printf("\n");
	return R;
}
void quickSort(int a[], int begin, int end, int size) {
	if (begin < end) {
		int p = partition(a, begin, end, size);
		quickSort(a, begin, p - 1, size);
		quickSort(a, p + 1, end, size);
	}
}
void QuickSort(void) {
	int size = 0;
	int a[100];
	int close = 1;

	printf("정렬할 개수 >> "); scanf_s("%d", &size);
	printf("정렬할 원소 입력(%d개, 띄어쓰기로 구분) >> ", size);
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &a[i]);
	}

	printf("\n[퀵 정렬 수행]\n");
	quickSort(a, 0, size - 1, size);
	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}


// 힙 정렬
void swap(int* a, int* b) {
	// 배열 요소 교환
	int temp = *a;
	*a = *b;
	*b = temp;
}
// 힙을 구성하는 함수
void heapify(int arr[], int n, int i) {
	int largest = i; // largest를 부모 노드로 초기화
	int left = 2 * i + 1; // 왼쪽 자식 노드
	int right = 2 * i + 2; // 오른쪽 자식 노드

	// 왼쪽 자식 노드가 부모 노드보다 크다면 largest 갱신
	if (left < n && arr[left] > arr[largest])
		largest = left;

	// 오른쪽 자식 노드가 부모 노드보다 크다면 largest 갱신
	if (right < n && arr[right] > arr[largest])
		largest = right;

	// largest가 변경되었다면 해당 노드와 부모 노드 교환
	if (largest != i) {
		swap(&arr[i], &arr[largest]);
		// 변경된 노드를 기준으로 다시 힙 구성
		heapify(arr, n, largest);
	}
}
// 힙 정렬 함수
void heapSort(int arr[], int n) {
	// 최대 힙(Max Heap) 구성
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// 힙 정렬 수행
	for (int i = n - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]); // 최대값(루트)을 맨 뒤로 보냄
		heapify(arr, i, 0); // 힙 구성을 통해 다시 정렬

		// 정렬 과정 출력
		printf("\n %d 단계 : ", n - i);
		for (int j = 0; j < n; j++) {
			printf(" %3d ", arr[j]);
		}
		printf("\n\n");
	}
}
void HeapSort(void) {
	int size = 0;
	int a[100];
	int close = 1;

	printf("정렬할 개수 >> "); scanf_s("%d", &size);
	printf("정렬할 원소 입력(%d개, 띄어쓰기로 구분) >> ", size);
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &a[i]);
	}

	printf("\n[힙 정렬 수행]\n");
	heapSort(a, size);
	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}


// 기수 정렬
// 입력된 배열의 최대값을 찾는 함수
int getMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
// 기수 정렬의 한 단계를 수행하는 함수
void countSort(int arr[], int n, int exp) {
	int output[50];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}
// 기수 정렬을 수행하는 함수
void radixSort(int arr[], int n) {
	int max = getMax(arr, n);
	int cnt = 0;
	for (int exp = 1; max / exp > 0; exp *= 10) {
		cnt++;
		countSort(arr, n, exp);

		printf(" %d 단계 : ", cnt);
		for (int i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}
void RadixSort(void) {
	int size = 0;
	int a[100];
	int close = 1;

	printf("정렬할 개수 >> "); scanf_s("%d", &size);
	printf("정렬할 원소 입력(%d개, 띄어쓰기로 구분) >> ", size);
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &a[i]);
	}

	printf("\n[기수 정렬 수행]\n");
	radixSort(a, size);
	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}


// 계수 정렬
void CointingSort(void) {
	int a[50];
	int size = 0;
	int close = 1;

	// 1. 카운팅 배열 선언/초기화
	int counting[101];
	for (int i = 0; i < 101; i++) {
		counting[i] = 0;
	}
	printf("정렬할 개수 >> "); scanf_s("%d", &size);
	printf("정렬할 원소 입력(%d개, 띄어쓰기로 구분) >> ", size);
	// 2. 카운팅 정렬 (입력)
	for (int i = 0; i < size; i++) {
		int input;
		scanf_s("%d", &input);
		counting[input]++;
	}

	printf("\n[계수 정렬 수행]\n");

	// 3. 카운팅 정렬 (출력)
	for (int i = 0; i < 101; i++) {
		// counting[i] 횟수만큼 i 출력
		for (int j = 0; j < counting[i]; j++) {
			printf(" %3d", i);
		}
	}

	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}


// 위상 정렬
#define MAX_VERTICES 100
// 정점 구조체
typedef struct Node2 {
	int vertex;
	struct Node2* next;
} Node;
// 그래프 구조체
typedef struct Graph2 {
	int numVertices;
	Node** adjLists;
	int* indegree;
} Graph;
// 정점 생성 함수
Node* createNode2(int v) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}
// 그래프 생성 함수
Graph* createGraph2(int vertices) {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->numVertices = vertices;

	graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
	graph->indegree = (int*)malloc(vertices * sizeof(int));

	for (int i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
		graph->indegree[i] = 0;
	}

	return graph;
}
// 간선 추가 함수
void addEdge2(Graph* graph, int src, int dest) {
	Node* newNode = createNode2(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	graph->indegree[dest]++;
}
void printGraph2(Graph* graph) {
	printf("\n그래프의 간선 정보:\n");
	for (int i = 0; i < graph->numVertices; i++) {
		Node* temp = graph->adjLists[i];
		while (temp != NULL) {
			printf("%d -> %d\n", i, temp->vertex);
			temp = temp->next;
		}
	}
}
// 위상 정렬 함수
void topologicalSort(Graph* graph) {
	int* result = (int*)malloc(graph->numVertices * sizeof(int));
	int* visited = (int*)malloc(graph->numVertices * sizeof(int));
	int front = 0, rear = 0, step = 0;

	for (int i = 0; i < graph->numVertices; i++) {
		visited[i] = 0;
		if (graph->indegree[i] == 0) {
			result[rear++] = i;
			visited[i] = 1;
		}
	}

	while (front != rear) {
		printf(" %d 단계 : ", ++step);
		int current = result[front++];
		printf("%d ", current);

		Node* temp = graph->adjLists[current];
		while (temp != NULL) {
			int adjVertex = temp->vertex;
			graph->indegree[adjVertex]--;
			if (graph->indegree[adjVertex] == 0 && !visited[adjVertex]) {
				result[rear++] = adjVertex;
				visited[adjVertex] = 1;
			}
			temp = temp->next;
		}
		printf("\n");
	}

	free(result);
	free(visited);
}
void TopologicalSort(void) {
	int vertices, edges;
	int close = 1;
	printf("정점의 수와 간선의 수를 입력하세요: ");
	scanf_s("%d %d", &vertices, &edges);

	Graph* graph = createGraph2(vertices);

	printf("간선 정보를 입력하세요 (출발 정점, 도착 정점):\n");
	for (int i = 0; i < edges; i++) {
		int src, dest;
		scanf_s("%d %d", &src, &dest);
		addEdge2(graph, src, dest);
	}
	printGraph2(graph);
	printf("\n[위상 정렬 수행]\n");
	topologicalSort(graph);
	printf("\n닫기(0 입력) >> ");
	while (close != 0) {
		scanf_s("%d", &close);
	}
}
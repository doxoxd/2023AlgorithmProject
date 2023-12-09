#pragma once
#include <stdio.h>
#include <stdlib.h>

// ���� Ʈ�� ��� ����ü
typedef struct Node10 {
    int key;
    struct Node10* left;
    struct Node10* right;
} Node10;

// �� ��� ����
Node10* newNode(int item) {
    Node10* temp = (Node10*)malloc(sizeof(Node10));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// ���� Ʈ���� �� ����
Node10* insert10(Node10* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert10(node->left, key);
    else if (key > node->key)
        node->right = insert10(node->right, key);

    return node;
}

// ���� Ʈ������ �� �˻�
Node10* search(Node10* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

// �־��� ����� ���� ���� ���� ã��
Node10* minValueNode(Node10* node) {
    Node10* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// ���� Ʈ������ �� ����
Node10* deleteNode(Node10* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node10* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node10* temp = root->left;
            free(root);
            return temp;
        }

        Node10* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// ���� Ʈ���� ���� ��ȸ�Ͽ� �� ���
void inorder(Node10* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// �޸� ����
void freeTree(Node10* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void TreeSearch(void) {
    int close = 1;
    Node10* root = NULL;
    int choice, value;

    do {
        printf("\n���� �˻� Ʈ�� �۾� �޴�:\n");
        printf("1. ����\n");
        printf("2. �˻�\n");
        printf("3. ����\n");
        printf("4. ��� (���� ��ȸ)\n");
        printf("5. ����\n");
        printf("�۾��� �����ϼ���: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("������ ���� �Է��ϼ���: ");
            scanf_s("%d", &value);
            root = insert10(root, value);
            break;
        case 2:
            printf("ã�� ���� �Է��ϼ���: ");
            scanf_s("%d", &value);
            if (search(root, value) != NULL)
                printf("�� %d��(��) Ʈ������ ã�ҽ��ϴ�.\n", value);
            else
                printf("�� %d��(��) Ʈ������ ã�� ���߽��ϴ�.\n", value);
            break;
        case 3:
            printf("������ ���� �Է��ϼ���: ");
            scanf_s("%d", &value);
            root = deleteNode(root, value);
            break;
        case 4:
            printf("���� ��ȸ ���: ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            freeTree(root);
            printf("�����մϴ�...\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ùٸ� �������� �Է��ϼ���.\n");
        }
    } while (choice != 5);

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}

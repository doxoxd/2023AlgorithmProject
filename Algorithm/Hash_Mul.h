#pragma once
#include <stdio.h>
#include <stdlib.h>


// �ؽ� �Լ� - ���ϱ�
// Multiplicative hash function implementation
int hash_function(int key, int array_size) {
    float A = 0.618; // A is typically a constant between 0 and 1
    return (int)(array_size * ((key * A) - (int)(key * A)));
}

// Insert value into hash table
void insert(int hash_table[], int key, int value, int array_size) {
    int index = hash_function(key, array_size);
    hash_table[index] = value;
    printf("Ű %d�� �ε��� %d�� �ؽ̵Ǿ����ϴ�.\n", key, index);
}

// Retrieve value from hash table
int get(int hash_table[], int key, int array_size) {
    int index = hash_function(key, array_size);
    return hash_table[index];
}

// Remove value from hash table
void remove_key(int hash_table[], int key, int array_size) {
    int index = hash_function(key, array_size);
    hash_table[index] = -1; // Assuming -1 indicates an empty slot
    printf("Ű %d�� �ε��� %d���� �����Ǿ����ϴ�.\n", key, index);
}

// Check if a slot is empty (deleted)
int is_empty(int hash_table[], int key, int array_size) {
    int index = hash_function(key, array_size);
    return (hash_table[index] == -1); // -1 indicates an empty slot
}

// Print hash table
void print_table(int hash_table[], int array_size) {
    printf("\nHash Table:\n");
    for (int i = 0; i < array_size; ++i) {
        printf("[%d] = %d\n", i, hash_table[i]);
    }
}

void Hash_Mul(void) {
    int close = 1;
    int array_size;

    printf("�ؽ� ���̺��� ũ�⸦ �Է��ϼ���: ");
    scanf_s("%d", &array_size);

    int* hash_table = (int*)malloc(array_size * sizeof(int));

    printf("Ű-�� ���� ������ �Է��ϼ���: ");
    int num_pairs;
    scanf_s("%d", &num_pairs);

    printf("Ű-�� ���� �Է��ϼ���:\n");
    for (int i = 0; i < num_pairs; ++i) {
        int key, value;
        scanf_s("%d %d", &key, &value);
        insert(hash_table, key, value, array_size);
    }

    printf("ã���� �ϴ� Ű�� �Է��ϼ���: ");
    int key_to_find;
    scanf_s("%d", &key_to_find);

    int found_value = get(hash_table, key_to_find, array_size);
    printf("Ű %d�� �ش��ϴ� ��: %d\n", key_to_find, found_value);

    printf("������ Ű�� �Է��ϼ���: ");
    int key_to_remove;
    scanf_s("%d", &key_to_remove);
    remove_key(hash_table, key_to_remove, array_size);

    printf("%d�� �����Ǿ����� Ȯ���մϴ�.: %s\n", key_to_remove, is_empty(hash_table, key_to_remove, array_size) ? "Yes" : "No");
    print_table(hash_table, array_size);

    free(hash_table);

    printf("\n�ݱ�(0 �Է�) >> ");
    while (close != 0) {
        scanf_s("%d", &close);
    }
}
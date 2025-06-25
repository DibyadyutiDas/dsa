#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 101

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct HashTable {
    HashNode *buckets[TABLE_SIZE];
} HashTable;

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % TABLE_SIZE;
}

HashTable* create_table() {
    HashTable *table = malloc(sizeof(HashTable));
    if (!table) return NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
        table->buckets[i] = NULL;
    return table;
}

void insert(HashTable *table, const char *key, int value) {
    unsigned int idx = hash(key);
    HashNode *node = table->buckets[idx];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            node->value = value;
            return;
        }
        node = node->next;
    }
    node = malloc(sizeof(HashNode));
    node->key = strdup(key);
    node->value = value;
    node->next = table->buckets[idx];
    table->buckets[idx] = node;
}

int* search(HashTable *table, const char *key) {
    unsigned int idx = hash(key);
    HashNode *node = table->buckets[idx];
    while (node) {
        if (strcmp(node->key, key) == 0)
            return &node->value;
        node = node->next;
    }
    return NULL;
}

void delete(HashTable *table, const char *key) {
    unsigned int idx = hash(key);
    HashNode *node = table->buckets[idx];
    HashNode *prev = NULL;
    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (prev)
                prev->next = node->next;
            else
                table->buckets[idx] = node->next;
            free(node->key);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void free_table(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode *node = table->buckets[i];
        while (node) {
            HashNode *tmp = node;
            node = node->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(table);
}

// Example usage
int main() {
    HashTable *table = create_table();
    insert(table, "apple", 1);
    insert(table, "banana", 2);

    int *val = search(table, "apple");
    if (val) printf("apple: %d\n", *val);

    delete(table, "apple");
    val = search(table, "apple");
    if (!val) printf("apple not found\n");

    free_table(table);
    return 0;
}
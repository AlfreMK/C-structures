#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Hash_Table_Entry **hash_table_init(int table_size) {
    Hash_Table_Entry **table = (Hash_Table_Entry **)malloc(table_size * sizeof(Hash_Table_Entry *));
    for (int i = 0; i < table_size; i++) {
        table[i] = NULL;
    }
    return table;
}


int hash_function(char *key, int table_size) {
    int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash_value = 31 * hash_value + key[i];
    }
    return hash_value % table_size;
}


void insert(Hash_Table_Entry **table, int table_size, char *key, int value) {
    int hash_value = hash_function(key, table_size);
    Hash_Table_Entry *entry = (Hash_Table_Entry *)malloc(sizeof(Hash_Table_Entry));
    entry->key = strdup(key);
    entry->value = value;
    entry->next = table[hash_value];
    table[hash_value] = entry;
}


int lookup(Hash_Table_Entry **table, int table_size, char *key) {
    int hash_value = hash_function(key, table_size);
    Hash_Table_Entry *entry = table[hash_value];
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}


void print_table(Hash_Table_Entry **table, int table_size) {
    for (int i = 0; i < table_size; i++) {
        printf("%d: ", i);
        Hash_Table_Entry *entry = table[i];
        while (entry != NULL) {
            printf("(%s, %d) ", entry->key, entry->value);
            entry = entry->next;
        }
        printf("\n");
    }
}


void free_table(Hash_Table_Entry **table, int table_size) {
    // Free the memory used by each entry in the table.
    for (int i = 0; i < table_size; i++) {
        Hash_Table_Entry *entry = table[i];
        while (entry != NULL) {
            Hash_Table_Entry *next_entry = entry->next;
            free(entry->key);
            free(entry);
            entry = next_entry;
        }
    }
    // Set all elements of the table to NULL.
    memset(table, 0, table_size * sizeof(Hash_Table_Entry *));
}

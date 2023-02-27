#pragma once
#include <stdio.h>


struct hash_table_entry;

typedef struct hash_table_entry Hash_Table_Entry;

// Define the struct for the hash table.
struct hash_table_entry {
    // example of information to store in the hash table: a key and a value (like a dictionary)
    char *key;
    int value;

    // pointer to the next entry in the hash table (for collision resolution)
    Hash_Table_Entry *next;
};

// Function to create a new hash table.
Hash_Table_Entry **hash_table_init(int table_size);

// Function to compute the hash value of a key.
int hash_function(char *key, int table_size);

// Function to insert a new key-value pair into the hash table.
void insert(Hash_Table_Entry **table, int table_size, char *key, int value);

// Function to look up a key in the hash table and return its value.
int lookup(Hash_Table_Entry **table, int table_size, char *key);

// Function to print the contents of the hash table.
void print_table(Hash_Table_Entry **table, int table_size);

// Function to free the memory used by the hash table.
void free_table(Hash_Table_Entry **table, int table_size);

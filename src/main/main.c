#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../structs/linked_list.h"
#include "../structs/binary_tree.h"
#include "../structs/hash_table.h"


int test_linked_list() {
    printf("Testing linked list...\n");

    // Create a linked list.
    List *list = list_init();

    // Add some elements to the list.
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);

    // Print the contents of the list.
    list_print(list);

    // Remove an element from the list.
    list_remove(list, 2);

    list_print(list);

    // Free the memory used by the list.
    list_destroy(list);

    return 0;
}



int test_binary_tree() {
    printf("Testing binary tree...\n");

    // Create a binary tree.
    Binary_tree *tree = bst_init();

    // Insert some elements into the tree.
    bst_append_node(tree, 5);
    bst_append_node(tree, 3);
    bst_append_node(tree, 7);
    bst_append_node(tree, 1);
    bst_append_node(tree, 4);
    bst_append_node(tree, 6);
    bst_append_node(tree, 8);

    // Print the contents of the tree.
    bst_console_log(tree->head);

    // Free the memory used by the tree.
    bst_destroy(tree->head);
    free(tree);

    return 0;
}


int test_hash_table() {
    printf("Testing hash table...\n");

    int table_size = 10;

    // Create a hash table.
    Hash_Table_Entry **table = hash_table_init(table_size);

    // Insert some key-value pairs into the table.
    insert(table, table_size, "hello", 1);
    insert(table, table_size, "world", 2);
    insert(table, table_size, "foo", 3);
    insert(table, table_size, "bar", 4);

    // Print the contents of the table.
    print_table(table, table_size);

    // Look up some keys in the table.
    printf("hello: %d (should be 1)\n", lookup(table, table_size, "hello"));
    printf("world: %d (should be 2)\n", lookup(table, table_size, "world"));

    // Free the memory used by the table.
    free_table(table, table_size);
    free(table);

    return 0;
}



int main() {
    // Test linked list.
    test_linked_list();

    // Test binary tree.
    test_binary_tree();

    // Test hash table.
    test_hash_table();

    // Return success.
    return 0;
}

// run the program
// ./main

// run with valgrind to check for memory leaks
// valgrind --leak-check=full ./main
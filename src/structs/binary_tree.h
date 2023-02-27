#pragma once
#include <stdio.h>


struct binary_tree_node;

typedef struct binary_tree_node Bt_Node;

struct binary_tree_node {
  // info that the node holds
  int index;
  
  Bt_Node* left;
  Bt_Node* right;
};

struct binary_tree;
typedef struct binary_tree Binary_tree;

struct binary_tree {
  Bt_Node* head;
};

// create a new tree
Binary_tree* bst_init();

// append a node to the tree
void bst_append_node(Binary_tree* tree, int index);

// recursive function to append a node to the tree
void recursive_node_append(Bt_Node* node_parent, Bt_Node* node_child);

// destroy the children of a node
void bst_destroy(Bt_Node* node);

// print the tree
void bst_console_log(Bt_Node* node);

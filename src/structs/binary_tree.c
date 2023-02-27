#include "binary_tree.h"
#include <stdlib.h>
#include <stdio.h>


Binary_tree* bst_init() {
	Binary_tree* bst = calloc(1, sizeof(Binary_tree));
	bst -> head = NULL;

	return bst;
}


void bst_append_node(Binary_tree* tree, int index) {
	Bt_Node* node = calloc(1, sizeof(Bt_Node));
	node -> index = index;
	node -> left = NULL;
	node -> right = NULL;

	if(tree -> head == NULL) {
		tree -> head = node;
	}
	else{
		recursive_node_append(tree -> head, node);
	}
}


void recursive_node_append(Bt_Node* node_parent, Bt_Node* node_child) {
    if (node_child->index <= node_parent->index) {
        if (node_parent->left == NULL){
            node_parent->left = node_child;
        }
        else{
            recursive_node_append(node_parent->left, node_child);
        }
    }
    else if (node_child->index > node_parent->index) {
        if (node_parent->right == NULL){
            node_parent->right = node_child;
        }
        else{
            recursive_node_append(node_parent->right, node_child);
        }
    }
}


void bst_destroy(Bt_Node* node) {
	if (node != NULL) {
		bst_destroy(node->left);
		bst_destroy(node->right);
		free(node);
	}
}


void bst_console_log(Bt_Node* node){
  if (node != NULL){
    bst_console_log(node->left);
    printf("%i\n", node->index);
    bst_console_log(node->right);
  }
}

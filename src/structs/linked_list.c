#include "linked_list.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


List* list_init() {
	List* list = calloc(1, sizeof(List));
	list -> head = NULL;
	list -> tail = NULL;
	return list;
}


void list_append (List* list, int index) {
	Node* node = calloc (1, sizeof(Node));
	node -> index = index;
	node -> next = NULL;

	// Si la lista está vacía entonces queda como el primer elemento
	if(list -> head == NULL) {
		list -> head = node; 
	}
	// Sino, se pone como el siguiente del ultimo
	else {
		list -> tail -> next = node;
	}
	// Luego se deja a este nodo como el último de la lista
	list -> tail = node;
}


void list_destroy (List* list) {
	// Liberamos los nodos
	if (list -> head) {
		Node* curr = list -> head -> next;
		Node* prev = list -> head;
		while (curr) {
		free (prev);
		prev = curr;
		curr = curr -> next;
		}
		free (prev);
	}
	// Liberamos la lista
	free (list);
}


void list_remove (List* list, int index) {
	if(list -> head) {
		Node* curr = list -> head -> next;
		Node* prev = list -> head;
		if (prev->index==index) {
			free(prev);
			list->head = curr;
		}
		else {
			while(curr) {
				if ((curr->index==index) & (list->tail->index==index)) {
					prev->next = NULL;
					list->tail = prev;
					free(curr);
					break;
				}
				if (curr->index==index) {
					prev->next = curr->next;
					free(curr);
					break;
				}
				prev = curr;
				curr = curr -> next;
			}
		}
	}
}


void list_print(List* list) {
	printf("-----------------------------\n");
	if (list->head) {
		for(Node* current = list -> head; current; current = current -> next) {
			printf("index: %i\n", current -> index);
		}
  }
}

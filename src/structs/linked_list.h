#pragma once

// Declaramos el struct para un nodo de la lista
struct linked_list_node;

// Definimos un alias para el struct nodo.
// La sintaxis es "typedef tipo alias"
typedef struct linked_list_node Node;

// Definimos el struct nodo
struct linked_list_node {
  // El valor que guarda el nodo 
  int index;
  // Un puntero al siguiente nodo de la lista 
  Node* next;
};

// Declaramos el struct para la lista
struct linked_list;
// Definimos un alias para el struct lista
typedef struct linked_list List;

// Definimos el struct lista
struct linked_list {
  // El primer nodo de la lista 
  Node* head;
  // El último nodo de la lista 
  Node* tail;
};

// Declaramos las funciones asociadas

// Inicializa una lista vacía 
List* list_init();

// Inserta un nuevo elemento al final de la lista 
void list_append(List* list, int index);

// Elimina un elemento de la lista
void list_remove(List* list, int index);

// Libera todos los recursos asociados a esta lista 
void list_destroy(List* list);

// Recorre la lista y la imprime
void list_print(List* list);

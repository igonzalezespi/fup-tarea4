#ifndef CONTACT_LIST_TREE_H_INCLUDED
#define CONTACT_LIST_TREE_H_INCLUDED

#include "contact_list.h"

typedef struct node {
  contact* data;
  // Se me da mal distinguir derecha/izquierda. Sería: first=izquierda;second=derecha
  struct node* first;
  struct node* second;
} node;

node* create_node(contact* data);
void insert_node(contact* data);
void delete_node(contact* data);
node* search(const char name[150]);
void display_tree(node* nd);

#endif // CONTACT_LIST_TREE_H_INCLUDED

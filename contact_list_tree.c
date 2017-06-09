#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "common.h"
#include "contact_list_tree.h"

node* create_node(contact* con) {
  node* new_node = (node*)malloc(sizeof(node));
  if(new_node == NULL) {
    return NULL;
  }
  new_node->data = con;
  new_node->first = NULL;
  new_node->second = NULL;
  return new_node;
}

node* insert_node(node *root, contact* data) {
  if(root == NULL) {
    root = create_node(data);
  } else {
    int is_left  = 0;
    int r        = 0;
    node* cursor = root;
    node* prev   = NULL;

    while(cursor != NULL) {
      r = alphabetize(data->name, cursor->data->name);
      prev = cursor;
      if(r < 0) {
        is_left = 1;
        cursor = cursor->first;
      } else if(r > 0) {
        is_left = 0;
        cursor = cursor->second;
      }
    }
    if(is_left)
      prev->first = create_node(data);
    else
      prev->second = create_node(data);
  }
  return root;
}

node* search(node* root, char name[150]) {
  if(root == NULL)
    return NULL;

  int r;
  node* cursor = root;
  while(cursor != NULL) {
    r = alphabetize(name, cursor->data->name);
    if(r < 0)
      cursor = cursor->first;
    else if(r > 0)
      cursor = cursor->second;
    else
      return cursor;
  }
  return cursor;
}

void display_tree(node* nd) {
  if (nd == NULL)
    return;
  printf("%s",nd->data->name);
  if(nd->first != NULL)
    printf("(L:%s)",nd->first->data->name);
  if(nd->second != NULL)
    printf("(R:%s)",nd->second->data->name);
  printf("\n");

  display_tree(nd->first);
  display_tree(nd->second);
}

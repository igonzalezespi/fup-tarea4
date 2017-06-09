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

void insert_node(contact* data) {
  if(root == NULL) {
    root = create_node(data);
  } else {
    int is_first  = 0;
    int r        = 0;
    node* cursor = root;
    node* prev   = NULL;

    while(cursor != NULL) {
      r = int_compare(data->number, cursor->data->number);
      prev = cursor;
      if(r < 0) {
        is_first = 1;
        cursor = cursor->first;
      } else if(r > 0) {
        is_first = 0;
        cursor = cursor->second;
      }

    }
    if(is_first)
      prev->first = create_node(data);
    else
      prev->second = create_node(data);
  }
}

// TODO: DEJAR LAS FUNCIONES INSERT Y DELETE PASANDO EL ROOT... SON RESURSIVAS

void delete_node(contact* data) {
  if(root == NULL)
    return NULL;

  node *cursor;
  int r = int_compare(data->number, root->data->number);
  if( r < 0)
    root->first = delete_node(root->first, data);
  else if( r > 0 )
    root->second = delete_node(root->second, data);
  else {
    if (root->first == NULL) {
      cursor = root->second;
      free(root->data->name);
      free(root->data);
      free(root);
      root = cursor;
    } else if (root->second == NULL) {
      cursor = root->first;
      free(root->data->name);
      free(root->data);
      free(root);
      root = cursor;
    } else { //2 children
      cursor = root->second;
      node *parent = NULL;

      while(cursor->first != NULL) {
        parent = cursor;
        cursor = cursor->first;
      }
      root->data = cursor->data;
      if (parent != NULL)
        parent->first = delete_node(parent->first, parent->first->data);
      else
        root->second = delete_node(root->second, root->second->data);
    }
  }
}

node* search(const int number) {
  if(root == NULL)
    return NULL;

  int r;
  node* cursor = root;
  while(cursor != NULL) {
    r = int_compare(number, cursor->data->number);
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
    printf("(IZQ:%s)",nd->first->data->name);
  if(nd->second != NULL)
    printf("(DER:%s)",nd->second->data->name);
  puts("");

  display_tree(nd->first);
  display_tree(nd->second);
}

/////////

int int_compare(int first, int second) {
  if(first > second)
    return 1;
  if(first < second)
    return -1;
  return 0;
}

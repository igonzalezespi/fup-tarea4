#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#include "common.h"
#include "contact_list.h"
#include "contact_list_tree.h"

void add_contact() {
  char aux[150];

  contact* new_contact = (contact*)malloc(sizeof(contact));

  if (new_contact == NULL) {
    goto mem_err;
  }
  puts("Nombre:");
  scanf(" %150s", aux);
  new_contact->name = (char*)malloc(strlen(aux) * sizeof(char));
  strcpy(new_contact->name, aux);
  if (new_contact->name == NULL) {
    goto mem_err;
  }

  puts("Numero de contacto:");
  scanf(" %10s", aux);
  new_contact->number = atoi(aux);

  insert_node(new_contact);
  if (root == NULL) {
    free(new_contact->name);
    free(new_contact);
mem_err:
    puts(INSUFFICIENT_MEMORY);
  }
}

void search_contact() {
  char name[150];
  puts("Nombre de contacto:");
  scanf(" %150s", name);
  node* found = search(name);
  printf("Numero: %i", found->data->number);
}

void list_all_contact() {
  display_tree(root);
}

//////

int search_compare(contact* first, contact* second) {
  if(first->name == second->name)
    return 1;
  return 0;
}


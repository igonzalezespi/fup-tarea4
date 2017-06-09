#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "common.h"
#include "contact_list.h"
#include "contact_list_tree.h"

void add_contact() {
  char aux[150];
  contact* new_contact = (contact*)malloc(sizeof(contact));
  node* already_exists;

  if (new_contact == NULL) {
    goto mem_err;
  }
  puts("Nombre:");
  scanf(" %150s", aux);
  already_exists = search(root, aux);

  if (already_exists == NULL) {
    new_contact->name = (char*)malloc(strlen(aux) * sizeof(char));
    strcpy(new_contact->name, aux);
    if (new_contact->name == NULL) {
      goto mem_err;
    }

    puts("Numero de contacto:");
    scanf(" %10s", aux);
    new_contact->number = atoi(aux);

    root = insert_node(root, new_contact);
    if (root == NULL) {
      free(new_contact->name);
      free(new_contact);
mem_err:
      puts(INSUFFICIENT_MEMORY);
    }
  } else {
    free(new_contact);
    puts("El contacto ya existe");
  }
}

void search_contact() {
  char name[150];
  puts("Nombre de contacto:");
  scanf(" %150s", name);
  node* found = search(root, name);
  if (found != NULL) {
    printf("Numero: %i\n", found->data->number);
  } else {
    puts("Contacto no encontrado");
  }
}

void list_all() {
  display_tree(root);
}


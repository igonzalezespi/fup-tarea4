//// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#include "common.h"
#include "contact_list.h"

node* root = NULL;

//// Main

int main() {
  SetConsoleTitle(TITLE);
  execute();
  system("PAUSE");
  return (EXIT_SUCCESS);
}

//// Primary functions

void show_menu() {
  CLEARSCR;
  puts("======================");
  puts("Seleccione una opcion");
  puts("======================");
  puts("");
  puts("# Acciones");
  puts("  N - Nuevo");
  puts("  B - Buscar");
  puts("  L - Listar");
  puts("  S - Salir");
}

char get_option() {
  char aux;
  scanf(" %c", &aux); // Ignoring trailing whitespace
  if (islower(aux)) {
    aux = toupper(aux); // Comparing to uppercase
  }
  return aux;
}

void execute() {
  char option;
  show_menu();
  option = get_option();
  CLEARSCR;
  if (option == 'N') {
    add_contact();
  } else if (option == 'B') {
    search_contact();
  } else if (option == 'L') {
    list_all_contact();
  } else if (option == 'S') {
    exit(EXIT_SUCCESS);
  }
  system("PAUSE");
  execute();
}











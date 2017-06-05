//// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#include "common.h"

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
  puts("   L - Listar catalogo");
  puts("   S - Salir");
  puts("");
  puts("# Clientes");
  puts("   1 - Alta");
  puts("   2 - Baja");
  puts("");
  puts("# Viajes");
  puts("   3 - Alta");
  puts("   4 - Eliminar");
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
  int pause = 0;
  show_menu();
  option = get_option();
  if (option == 'L') {
    display_all();
    pause = 1;
  } else if (option == 'S') {
    exit(EXIT_SUCCESS);
  } else if (option == '1') {
//    add_client();
    pause = 1;
  } else if (option == '2') {
//    remove_client();
    pause = 1;
  } else if (option == '3') {
//    add_travel();
    pause = 1;
  } else if (option == '4') {
//    remove_travel();
    pause = 1;
  } else if (option == 'D') {
//    undo_action();
  } else if (option == 'R') {
//    redo_action();
  }
  if (pause == 1) {
    system("PAUSE");
  }
  execute();
}

void display_all() {
  CLEARSCR;
  puts("/****** AGENCIA DE VIAJES *******/");
}

// Secondary functions

void set_filename(char filename[]) {
  char input[FILENAME_MAX_LENGTH];

  CLEARSCR;
  filename[0] = '\0';
  puts("Nombre del archivo:");
  scanf(" %49s", input);

  strcat(filename, "./");
  strcat(filename, input);
  clean_string(filename);
}

void clean_string(char c1[]) {
  int i;
  for (i = 0; i<strlen(c1); i++) {
    if (c1[i] == '\n') {
      c1[i] = '\0';
    }
  }
}

int alphabetize (char *a, char *b) {
  int r = strcasecmp(a, b);
  if (r) return r;
  return -strcmp(a, b);
}











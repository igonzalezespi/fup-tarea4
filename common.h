#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

//// Compatibility
#if defined POSIX
#define CLEARSCR system ( "clear" )
#elif defined MSDOS || defined WIN32
#define CLEARSCR system ( "cls" )
#endif

//// Application constants
#define TITLE               "AGENDA DE TELEFONOS"

// Errors
#define FILE_NOT_FOUND "ERROR. No existe el archivo."
#define INSUFFICIENT_MEMORY "ERROR. Memoria insuficiente."
#define CONTACT_NOT_FOUND "ERROR. Contacto no encontrado."

#include "contact_list_tree.h"

//// Prototypes
void show_menu(void);
char get_option(void);
void execute(void);

extern node* root;

#endif // COMMON_H_INCLUDED

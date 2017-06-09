#ifndef CONTACT_LIST_H_INCLUDED
#define CONTACT_LIST_H_INCLUDED

typedef struct contact {
  char* name;
  int number;
} contact;

void add_contact(void);
void search_contact(void);
void list_all(void);

#endif // CONTACT_LIST_H_INCLUDED

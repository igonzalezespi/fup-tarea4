#ifndef CONTACT_LIST_H_INCLUDED
#define CONTACT_LIST_H_INCLUDED

typedef struct contact {
  char* name;
  int number;
} contact;

void add_contact(void);
void search_contact(void);
void list_all_contact(void);

int int_compare(int first, int second);
int search_compare(contact* first, contact* second);

#endif // CONTACT_LIST_H_INCLUDED

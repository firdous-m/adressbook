#ifndef CONTACT_H
#define CONTACT_H
#include<string.h>
#define ERROR(msg)   printf("\033[1;31m%s\033[0m\n", msg)   // Red
#define SUCCESS(msg) printf("\033[1;32m%s\033[0m\n", msg)   // Green
#define WARNING(msg) printf("\033[1;33m%s\033[0m\n", msg)   // Yellow

typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;

typedef struct AddressBook_Data
{
    Contacts contact_details[100];
    int contact_count;
} AddressBook;

/* Function declarations */
// void init_intitalization(AddressBook *);
int create_contact(AddressBook *);
void list_contacts(AddressBook *);
int search_contacts(AddressBook *);
int edit_contact(AddressBook *);
int delete_contact(AddressBook *);
int save_contacts(AddressBook *);
int search_name(AddressBook *);
int search_mobile(AddressBook *);
int search_email(AddressBook *);
int name_validation(char str[]);
int number_validation(char str[]);
int mail_validation(char str[]);
int number_duplicate(AddressBook*,char str[]);
int mail_duplicate(AddressBook* adrressbook,char str[]);
void delete(AddressBook* AddressBook,int i);
void load_file_data(AddressBook*);







#endif // CONTACT_H
       // CONTACT_H
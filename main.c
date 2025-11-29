#include <stdio.h>
#include "contact.h"
#include <stdlib.h>
/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;
    load_file_data(&addressbook);

    // init_intitalization(&addressbook);
    system("chcp 65001 > nul");
printf("\t\t\t╔═══════════════════════════════════════════════════════════╗\n");
printf("\t\t\t║                     ADDRESS BOOK SYSTEM                   ║\n");
printf("\t\t\t╚═══════════════════════════════════════════════════════════╝\n");


    while (1)
    {
        printf("\nAddress book menu\n"); /* Give a prompt message for a user */
        printf("1.Add contact\n2.search contact\n3.Edit contact\n4.Delete contact\n5.Display contact\n6.Save contact\n7.Exit\n");
        printf("Enter the option : ");
        while(scanf("%d", &option)!=1)
        {
         int c;
         while ((c = getchar()) != '\n' && c != EOF) 
         {}
        ERROR("Invalid input! please enter a number");
        }
        getchar();

        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            create_contact(&addressbook);
            break;
        }

        case 2:
        {
            //printf("Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4. Exit\nEnter the option : "); /* Providing menu */
            search_contacts(&addressbook);
            break;
        }
        case 3:
            //printf("Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */

            edit_contact(&addressbook);
            break;

        case 4:
        {
            //printf("Delete Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "); /* Providing menu */

            delete_contact(&addressbook);
            break;
        }
        case 5:
        {
            printf("List Contacts:\n");
            list_contacts(&addressbook);
            break;
        }

        case 6:
            printf("Saving contacts\n");
            save_contacts(&addressbook);
            break;

        case 7:
            printf("INFO : Save and Exit...\n");
            return 0;

        default:
            ERROR("Invalid option \n");
            break;
        }
    }
    return 0;
}

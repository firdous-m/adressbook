#include <stdio.h>
#include "contact.h"
#include <string.h>

int create_contact(AddressBook *addressbook)
{
    char name[20];
    char mobile_number[20];
    char email_id[20];
    int i = 1, j = 1, k = 1;
    while (i)
    {
        while (1)
        {
            printf("Enter the name: ");
            scanf("%[^\n]", name);
            j = name_validation(name);
            getchar();
            if (j)
            {
                strcpy(addressbook->contact_details[addressbook->contact_count].Name, name);
                break;
            }
        }

        while (1)
        {
            printf("Enter the phone number: ");
            scanf("%[^\n]", mobile_number);
            j = number_validation(mobile_number);
            getchar();
            k = number_duplicate(addressbook, mobile_number);
            if (j && k)
            {
                strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number, mobile_number);
                break;
            }
        }
        while (1)
        {
            printf("Enter the email id: ");
            scanf("%[^\n]", email_id);
            j = mail_validation(email_id);
            getchar();
            k = mail_duplicate(addressbook, email_id);

            if (j && k)
            {
                strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID, email_id);
                break;
            }
        }
        addressbook->contact_count++;
        printf("\033[1;32m");
        printf("\n=====================================================\n");
        printf("   ✔ CONTACT SUCCESSFULLY CREATED\n");
        printf("=====================================================\n\n");
        printf("\033[0m");

        printf("Do you want to create another contact:\n1-yes\n0-No\n:-");
        scanf("%d", &i);
        getchar();
    }
    return 0;
}

void list_contacts(AddressBook *addressbook)
{
    if (addressbook->contact_count == 0)
    {
        WARNING("No contact details found\nadd contacts and try again");
    }
    else
    {
        printf("--------------------------------------------------------------------------\n");
        printf("| %-20s | %-15s | %-25s |\n",
               "Name", "Phone Number", "Email ID");
        printf("--------------------------------------------------------------------------\n");

        for (int i = 0; i < addressbook->contact_count; i++)
        {
            printf("| %-20s | %-15s | %-25s |\n",
                   addressbook->contact_details[i].Name,
                   addressbook->contact_details[i].Mobile_number,
                   addressbook->contact_details[i].Mail_ID);
            printf("--------------------------------------------------------------------------\n");
        }
    }
}

int search_contacts(AddressBook *addressbook)
{
    int found = -1;
    int i = 1, choice = 0;
    while (i)
    {
        printf("Search Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4. Exit\nEnter the option : "); /* Providing menu */
        while (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            ERROR("Invalid input! please enter a number");
        }
        getchar();
        switch (choice)
        {
        case 1:
            found = search_name(addressbook);
            if (found == -2)
            {
                ERROR("multiple contacts with same name found! try using mobile number of email id");
            }
            else if (found >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[found].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[found].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[found].Mail_ID);

                printf("\t\t\t==============================================\n\n");
            }
            else
            {
                ERROR("contact not found\n");
            }
            break;
        case 2:
            found = search_mobile(addressbook);
            if (found >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[found].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[found].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[found].Mail_ID);

                printf("\t\t\t==============================================\n\n");
            }
            else
            {
                ERROR("contact not found\n");
            }
            break;

        case 3:
            found = search_email(addressbook);
            if (found >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[found].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[found].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[found].Mail_ID);

                printf("\t\t\t==============================================\n\n");
            }
            else
            {
                ERROR("contact not found\n");
            }
            break;
        case 4:
            return 0;
            break;
        default:
            WARNING("Invalid input\n");
            break;
        }
        printf("Do want to search again?\n1-yes\n0-no\n");
        scanf("%d", &i);
    }
    return 0;
}

int edit_contact(AddressBook *addressbook)
{
    int choice, f = 1, pos = -1;
    char name[20];
    char number[20];
    char email_id[20];

    while (f)
    {
        printf("Wich contact do you want to edit?\nsearch by :\n1.Name \n2.Mobile number\n3.Mail ID\n4. Exit\nEnter the option : \n");
        while (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            ERROR("Invalid input! please enter a number");
        }
        getchar();
        switch (choice)
        {
        case 1:
            pos = search_name(addressbook);
            if (pos == -2)
            {
                ERROR("multiple contacts with same name found! try using mobile number of email id");
            }
            else if (pos >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[pos].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[pos].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[pos].Mail_ID);

                printf("\t\t\t==============================================\n\n");
            }
            else
            {
                ERROR("contact not found\n");
                break;
            }
            break;
        case 2:
            pos = search_mobile(addressbook);
            if (pos >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[pos].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[pos].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[pos].Mail_ID);

                printf("\t\t\t==============================================\n\n");
            }
            else
            {
                ERROR("contact not found\n");
                break;
            }
            break;
        case 3:
            pos = search_email(addressbook);
            if (pos >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[pos].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[pos].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[pos].Mail_ID);

                printf("\t\t\t==============================================\n\n");
            }
            else
            {
                ERROR("contact not found\n");
                break;
            }
            break;
        default:
            WARNING("Invalid input");
            break;
        }
        printf("Wich contact detail do you want to edit?\n1.name\n2.mobile number\n3.email id\n4.exit\n:-");
        while (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            ERROR("Invalid input! please enter a number");
        }
        getchar();
        int j, k;
        switch (choice)
        {
        case 1:
            while (1)
            {
                printf("Enter the new name: ");
                scanf("%[^\n]", name);
                j = name_validation(name);
                getchar();
                if (j)
                {
                    strcpy(addressbook->contact_details[pos].Name, name);
                    SUCCESS("╭──────────────────────────────────╮\n");
                    SUCCESS("│✏️ ✔ Contact Edited Successfully │\n");
                    SUCCESS("╰──────────────────────────────────╯\n");

                    break;
                }
            }
            break;
        case 2:
            while (1)
            {
                printf("Enter the new phone number: ");
                scanf("%[^\n]", number);
                j = number_validation(number);
                getchar();
                k = number_duplicate(addressbook, number);
                if (j && k)
                {
                    strcpy(addressbook->contact_details[pos].Mobile_number, number);
                    SUCCESS("╭──────────────────────────────────╮\n");
                    SUCCESS("│✏️ ✔ Contact Edited Successfully │\n");
                    SUCCESS("╰──────────────────────────────────╯\n");

                    break;
                }
            }
            break;
        case 3:
            while (1)
            {
                printf("Enter the new email id: ");
                scanf("%[^\n]", email_id);
                j = mail_validation(email_id);
                getchar();
                k = mail_duplicate(addressbook, email_id);

                if (j && k)
                {
                    strcpy(addressbook->contact_details[pos].Mail_ID, email_id);
                    SUCCESS("╭──────────────────────────────────╮\n");
                    SUCCESS("│✏️ ✔ Contact Edited Successfully │\n");
                    SUCCESS("╰──────────────────────────────────╯\n");

                    break;
                }
            }
            break;
        case 4:
            return 0;

        default:
            printf("invalid input");
            break;
        }
        printf("Do you want to edit more details: \n1-yes\n2-no");
        scanf("%d", &f);
        getchar();
    }
}

int delete_contact(AddressBook *addressbook)
{
    int choice, pos = -1, t;
    while (1)
    {
        printf("Wich contact do you want to delete?\nsearch by:\n1.name\n2.Mobile number\n3.Email id\n4.exit\nEnter your choice:");
        while (scanf("%d", &choice) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            ERROR("Invalid input! please enter a number");
        }
        getchar();
        switch (choice)
        {
        case 1:
            pos = search_name(addressbook);
            if (pos == -2)
            {
                ERROR("multiple contacts with same name found! try using mobile number of email id");
            }
            else if (pos >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[pos].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[pos].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[pos].Mail_ID);

                printf("\t\t\t==============================================\n\n");
                printf("Are you sure you want to delete this contact?\n1-YES\n0-NO\n");
                scanf("%d", &t);
                if (t)
                {
                    delete(addressbook, pos);
                }
                break;
            }

            else
            {
                ERROR("contact not found\n");
                break;
            }

        case 2:
            pos = search_mobile(addressbook);
            if (pos >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[pos].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[pos].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[pos].Mail_ID);

                printf("\t\t\t==============================================\n\n");
                printf("Are you sure you want to delete this contact?\n1-YES\n0-NO");
                scanf("%d", &t);
                if (t)
                {
                    delete(addressbook, pos);
                }
            }
            else
            {
                ERROR("contact not found\n");
                break;
            }

            break;
        case 3:
            pos = search_email(addressbook);
            if (pos >= 0)
            {
                printf("\n\t\t\t==============================================\n");
                printf("\t\t\t                CONTACT FOUND                \n");
                printf("\t\t\t==============================================\n");

                printf("\t\t\t| %-15s : %-25s |\n", "Name", addressbook->contact_details[pos].Name);
                printf("\t\t\t| %-15s : %-25s |\n", "Phone Number", addressbook->contact_details[pos].Mobile_number);
                printf("\t\t\t| %-15s : %-25s |\n", "Email ID", addressbook->contact_details[pos].Mail_ID);

                printf("\t\t\t==============================================\n\n");
                printf("Are you sure you want to delete this contact?\n1-YES\n0-NO");
                scanf("%d", &t);
                if (t)
                {
                    delete(addressbook, pos);
                }
            }
            else
            {
                ERROR("contact not found\n");
                break;
            }

            break;
        case 4:
            return 0;
        default:
            printf("Invalid input");
            break;
        }
        printf("Do you want to delete more contacts?\n1-yes\n0-no\n");
        if (scanf("%d", &choice) != 1)
        {
            ERROR("Invalid input! please enter a number");
        }
        if (!choice)
            return 0;
    }

    return 0;
}
int save_contacts(AddressBook *addressbook)
{
    FILE *fp = fopen("contact.txt", "w+");
    fprintf(fp, "%d\n", addressbook->contact_count);
    for (int i = 0; i < addressbook->contact_count; i++)
    {

        fprintf(fp, "%s,%s,%s\n", addressbook->contact_details[i].Name, addressbook->contact_details[i].Mobile_number, addressbook->contact_details[i].Mail_ID);
    }
    SUCCESS("╭──────────────────────────────────╮\n");
    SUCCESS("│💾  ✔ Contact Saved Successfully  │\n");
    SUCCESS("╰──────────────────────────────────╯\n");

    fclose(fp);
    return 0;
}
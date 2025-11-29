#include <stdio.h>
#include "contact.h"
#include <stdlib.h>
void load_file_data(AddressBook* AddressBook)
{
     
    FILE* fp=fopen("contact.txt","r");
    fscanf(fp,"%d\n",&AddressBook->contact_count);
    for(int i=0;i<AddressBook->contact_count;i++)
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",AddressBook->contact_details[i].Name,AddressBook->contact_details[i].Mobile_number,AddressBook->contact_details[i].Mail_ID);
    }
    fclose(fp);
}
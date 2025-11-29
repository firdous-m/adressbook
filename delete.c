#include <stdio.h>
#include "contact.h"
#include <string.h>
void delete(AddressBook* addressBook,int pos)
{
     int j = pos+1;
    for (int i = pos; i< addressBook->contact_count-1; i++)
    {
        
            strcpy(addressBook->contact_details[i].Name,addressBook->contact_details[j].Name);
            strcpy(addressBook->contact_details[i].Mobile_number,addressBook->contact_details[j].Mobile_number);
            strcpy(addressBook->contact_details[i].Mail_ID,addressBook->contact_details[j].Mail_ID);
            
          
            j++;
    }
    (addressBook->contact_count)--;
    
SUCCESS("╭──────────────────────────╮\n");
SUCCESS("│   🗑️  ✔  Delete Success   │\n");
SUCCESS("╰──────────────────────────╯\n");


}
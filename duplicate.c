#include <stdio.h>
#include "contact.h"
#include<string.h>
int number_duplicate(AddressBook* adrressbook,char str[])
{
   for(int i=0;i<adrressbook->contact_count;i++)
   {
        if(strcmp(str,adrressbook->contact_details[i].Mobile_number)==0)
        {
            WARNING("phone number already exist! try another");
            return 0;
        }
   }
   return 1;
}
int mail_duplicate(AddressBook* adrressbook,char str[])
{
   for(int i=0;i<adrressbook->contact_count;i++)
   {
        if(strcmp(str,adrressbook->contact_details[i].Mail_ID)==0)
        {
            WARNING("mail id already exist! try another");
            return 0;
        }
   }
   return 1;
}

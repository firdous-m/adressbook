#include<stdio.h>
#include<string.h>
#include"contact.h"
int search_name(AddressBook *addressbook)
{
    char str[20];
    int found=0,flag;int i=1,count=0;
    while(i)
    {
    printf("enter the name: ");
    scanf("%[^\n]",str);
    getchar();
    for(int i=0;i<addressbook->contact_count;i++)
    {
    if((strcmp(str,addressbook->contact_details[i].Name)==0))
    {
        found=1;
        flag=i;
        count++;
    }
}
    
if(found && count==1)
{
    return flag;
}
else if(count>1)
{
    return -2;
}
else
{
    return -1;
}
    }


}
int search_mobile(AddressBook *addressbook)
{
   {
    char str[20];
    int found=0,flag;int i=1;
    while(i)
    {
    printf("enter the mobile number: ");
    scanf("%[^\n]",str);
    getchar();
    for(int i=0;i<addressbook->contact_count;i++)
    {
    if((strcmp(str,addressbook->contact_details[i].Mobile_number)==0))
    {
        found=1;
        flag=i;
        break;
    }
}
if(found)
{
    return flag;
}
else
{
    
    return -1;
}

    }
}
}
int search_email(AddressBook *addressbook)
{
    char str[20];
    int found,flag;
    printf("enter the email id: ");
    scanf("%[^\n]",str);
    getchar();
    for(int i=0;i<addressbook->contact_count;i++)
    {
    if((strcmp(str,addressbook->contact_details[i].Mail_ID)==0))
    {
        found=1;
        flag=i;
        break;
    }
}
return flag;

}

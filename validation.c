#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
int number_validation(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            ERROR("invalid phone number! it should only contain digits. try again!");
            return 0;
        }
        i++;
    }

    int len = strlen(str);
    if (len != 10)
    {
        ERROR("invalid phone number! total digit should be equal to 10. try again!");
        return 0;
    }

    if (str[0] < '6')
    {
        ERROR("first digit of the phone number should be greater than or equal to 6. try again!");
        return 0;
    }
    return 1;
}
int name_validation(char str[])
{
    int i = 0;
    int flag = 0;
    if (str[0] == '\n')
    {
        ERROR("Name cannot be empty\n");
        return 0;
    }
    while (str[i] != '\0')
    {
        if (!(isalpha(str[i]) || str[i] == ' '))
        {
            ERROR("invalid format! name should only contain alphabets. try again!");
            return 0;
        }
        i++;
    }
    return 1;
}
int mail_validation(char mail_id[])
{
    int len = strlen(mail_id);

    int at_count = 0, dot_count = 0, at_pos = -1, dot_pos = -1;
    for (int i = 0; i < len; i++)
    {
        if (mail_id[i] >= 'a' && mail_id[i] <= 'z' || mail_id[i] == '@' || mail_id[i] == '.' || mail_id[i] >= '0' && mail_id[i] <= '9')
        {
            if (mail_id[i] == '@')
            {
                at_count++;
                at_pos = i;
            }
            if (mail_id[i] == '.')
            {
                dot_count++;
                dot_pos = i;
            }
        }
        else
        {
            ERROR("invalid mail id format. Mail Id should only contain '@' symbol, full stop (•), numbers and lowercase letters! Try again.\n");
            return 0;
        }
    }
    if (dot_pos == 0)
    {
        ERROR("invalid mail id format. Mail id do not start with (.) ! Try again.\n");
        return 0;
    }
    if (at_count < 1)
    {
        ERROR("invalid mail id format. @ symbol is missing ! Try again.\n");
        return 0;
    }
    if (at_pos < 1)
    {
        ERROR("invalid mail id format. Before @ some characters must be present ! Try again.\n");
        return 0;
    }

    if (at_count > 1)
    {
        ERROR("invalid mail id format. Only One @ symbol must be present/ Try again.\n");
        return 0;
    }
    if (dot_count > 1)
    {
        ERROR("invalid mail id format. Only One (.) symbol must be present/ Try again.\n");
        return 0;
    }
    if (dot_count < 1)
    {
        ERROR("invalid mail id format. Atleast One (.) symbol must be present/ Try again.\n");
        return 0;
    }
    if (dot_pos < at_pos)
    {
        ERROR("invalid mail id format\n '.' should not be present before @");
        return 0;
    }
    if (dot_pos < at_pos + 2)
    {
        ERROR("invalid mail id format. Domain name is absent\n");
        return 0;
    }
    int i=0,count=0;
    while(i<at_pos)
    {
        if(mail_id[i]>=97 && mail_id[i]<=120)
        {   
            count++;
            break;
        }
        i++;
    }
    if(count==0)
    {
       ERROR("invalid email id format. atleast one character must be present before @");
       return 0;
    }

    for (int i = at_pos + 1; i < dot_pos; i++)
    {
        if (mail_id[i] >= 'a' && mail_id[i] <= 'z')
        {
        }
        else
        {
            ERROR("There must be only lowercase letters between @ and (.) ! Try again.\n");
            return 0;
        }
    }
    if (dot_pos > len)
    {
        ERROR("There must be some characters will present after (.) ! Try again.\n");
        return 0;
    }
    for (int i = dot_pos + 1; i < len; i++)
    {
        if (mail_id[i] >= 'a' && mail_id[i] <= 'z')
        {
        }
        else
        {
            ERROR("There must be lower case letter after (.) ! Try again.\n");
            return 0;
        }
    }
    return 1;
}

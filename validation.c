#include<stdio.h>
#include<string.h>
#include"contact.h"
int number_validation(char str[])
{
     int i=0;
      while(str[i]!='\0')
    {
        if(!(str[i]>='0'&& str[i]<='9'))
        {
            ERROR("invalid phone number! it should only contain digits. try again!");
            return 0;
        }
        i++;
    }
    int len=strlen(str);
    if(len!=10)
    {
       ERROR("invalid phone number! total digit should be equal to 10. try again!");
        return 0;
    }
   
    if(str[0]<'6')
    {
        ERROR("first digit of the phone number should be greater than or equal to 6. try again!");
        return 0;
    }
       return 1;
   

}
int name_validation(char str[])
{
    int i=0;
    int flag=0;
    while(str[i]!='\0')
    {
        if(!(str[i]>='A'&& str[i]<='Z'|| str[i]==' '||str[i]>='a'&& str[i]<='z'))
        {
            ERROR("invalid format! name should only contain alphabets. try again!");
              flag=1;
              break;
        }
        i++;
    }
    if(flag==0)
    return 1;
    else
    {
    return 0;
    }
}
int mail_validation(char str[])
{
 char domain[] = {"@gmail.com"};
    int l1 = strlen(domain);
    int l2 = strlen(str);
    if (l2 < l1)
    {
        ERROR("Inavlid email id\nproblem:mail id too short\n");
        return 0;
    }
    int flag = 1, j = 0;
    for (int i = l2 - l1; i < l1; i++)
    {
        if (str[i] != domain[j])
            flag = 0;
        j++;
    }
    if (!flag || str[0] == '.')
    {
        ERROR("Inavlid email id format\nproblem:must contain domain\n");
        return 0;
    }
    for (int i = 0; i < l1 - l2; i++)
    {
        if (!((str[i] >= 0 && str[i] <= 9) || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
        {
            ERROR("Invalid email id format\nproblem:special characters not allowed\n");
            return 0;
        }
    }
    return 1;
}
/*
✅ Email Validation Rules
1. Must contain exactly one @ symbol

No missing @

No multiple @

2. Email must not contain spaces

Spaces anywhere make it invalid.

3. Local part (before @) rules

Cannot be empty.

Cannot start with a dot (.).

Cannot end with a dot (.).

Cannot have consecutive dots (..).

Maximum length: 64 characters.

Allowed characters:

Letters (A–Z, a–z)

Digits (0–9)

Special characters:

. _ % + - ! # $ & ' * / = ? ^ ` { | } ~

4. Domain part (after @) rules

Cannot be empty.

Maximum length: 255 characters.

Must contain one or more labels separated by dots.

5. Domain label rules (each part between dots)

Cannot be empty.

Length must be 1 to 63 characters.

Must start with an alphanumeric (letter or digit).

Must end with an alphanumeric.

Middle characters may include:

Letters

Digits

Hyphens -

No consecutive dots.

6. TLD (final part after last dot)

Must be at least 2 characters (like .com, .in, .org)

Must contain only letters (no numbers, no hyphens)

7. Overall length rule

Full email length should not exceed 320 characters.

8. No forbidden characters

No spaces

No commas

No semicolons

No parentheses

No quotes

No backslashes (unless advanced escaping rules used, usually not)
*/
#ifndef declare_h
#define declare_h

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
typedef struct
{
    int year;
    int month;
    int day;
}birth_date;

typedef struct
{
    char first_name[150];
    char last_name[150];
    birth_date brthdt;
    char address[150];
    char e_mail[150];
    char number[150];
}telephonebk;

#endif

#include "declare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "load.h"

void saveToFile(telephonebk arr_contacts[],int q,int count)
{
    FILE *telephonebook;
    telephonebook = fopen("phonebook.txt", "w");
    count = count-1;
    while(count!=-1)
    {
        fprintf(telephonebook,"%s,%s,%d-%d-%d,%s,%s,%s\n", arr_contacts[count].last_name, arr_contacts[count].first_name, arr_contacts[count].brthdt.day, arr_contacts[count].brthdt.month, arr_contacts[count].brthdt.year, arr_contacts[count].address, arr_contacts[count].e_mail, arr_contacts[count].number);
        count--;
    }
    fclose(telephonebook);
    count =0;
    load(count);
}

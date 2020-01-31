#include "declare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void contentPrint(telephonebk arr_contacts[],int q)
{
    printf("\n");
    printf("First Name : %s\n",arr_contacts[q].first_name);
    printf("Last Name : %s\n",arr_contacts[q].last_name);
    printf("Day Of Birth : %d\n",arr_contacts[q].brthdt.day);
    printf("Month Of Birth : %d\n",arr_contacts[q].brthdt.month);
    printf("Year Of Birth : %d\n",arr_contacts[q].brthdt.year);
    printf("Address : %s\n",arr_contacts[q].address);
    printf("Email : %s\n",arr_contacts[q].e_mail);
    printf("Phone : %s\n",arr_contacts[q].number);
}

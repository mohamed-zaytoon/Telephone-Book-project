#include "declare.h"
#include "load.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void deleteContent(telephonebk arr_contacts[],int q,int count)
{
    int res;
    int ch;
    char va[2]={"1"};
    if (!count)
    {
        printf("CONTACTS EMPTY\n");
        return;
    }
    res = search(va,arr_contacts,count,&ch);
    if (res)
    {

        arr_contacts[ch]=arr_contacts[count-1];
        count--;
    }

     getContent(arr_contacts,count);

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "declare.h"
#include "add.h"
#include "contentprint.h"
#include "delete.h"
#include "end.h"

FILE *telephonebook;
telephonebk arr_contacts[150];
int count = 0;
int q = 0;
void getContent(telephonebk arr_contacts[],int count);
void load(int count)
{
    telephonebook = fopen("phonebook.txt", "r");
    if (telephonebook == NULL)
        printf("file not exist\n");
    if(NULL!=telephonebook)
    {
        fseek(telephonebook,0,SEEK_END);
        int size =ftell(telephonebook);
        if(size==0)
        {
            printf("FILE IS EMPTY\n");
            printf("choose:\n1.enter data\n2.exit\n");
            char operation[50];
            scanf(" %s",operation);
            int len = strlen(operation);
            if(len == 1)
            {
                char newoper[1];
                strcpy(newoper,operation);
                if(strcmp(newoper,"1")==0)
                {
                    add(arr_contacts,count);
                    load(count);
                }
                else if(strcmp(newoper,"2")==0)
                    end(arr_contacts,q,count);
                else
                    printf("ERROR, enter number from 1 or 2\n");
            }
            else
                printf("ERROR, enter number from 1 or 2\n");

        }
        else
        {
            fseek(telephonebook,0,SEEK_SET);
            while(!feof(telephonebook))
            {
                fscanf(telephonebook,"%[^,],",arr_contacts[count].last_name);
                fscanf(telephonebook,"%[^,],",arr_contacts[count].first_name);
                fscanf(telephonebook,"%d-",&arr_contacts[count].brthdt.day);
                fscanf(telephonebook,"%d-",&arr_contacts[count].brthdt.month);
                fscanf(telephonebook,"%d,",&arr_contacts[count].brthdt.year);
                fscanf(telephonebook,"%[^,],",arr_contacts[count].address);
                fscanf(telephonebook,"%[^,],",arr_contacts[count].e_mail);
                fscanf(telephonebook," %s\n",arr_contacts[count].number);
                count++;
            }
            fclose(telephonebook);
            count = getCount(count);
            getContent(arr_contacts,count);
        }
    }

}
void getContent(telephonebk arr_contacts[],int count)
{
    while(1)
    {
        printf(" 1.query\n 2.add\n 3.delete\n 4.modify\n 5.print\n 6.save\n 7.exit\n");
        char operation[50];
        scanf(" %s",operation);
        int len = strlen(operation);
        if(len == 1)
        {
            char newoper[1];
            strcpy(newoper,operation);
            if(strcmp(newoper,"1")==0)
                query(arr_contacts,count);
            else if(strcmp(newoper,"2")==0)
                add(arr_contacts,count);
            else if(strcmp(newoper,"3")==0)
                deleteContent(arr_contacts,q,count);
            else if(strcmp(newoper,"4")==0)
                modify(arr_contacts,q,count);
            else if(strcmp(newoper,"5")==0)
                pSort(arr_contacts,q,count);
            else if(strcmp(newoper,"6")==0)
                saveToFile(arr_contacts,q,count);
            else if(strcmp(newoper,"7")==0)
                end(arr_contacts,q,count);
            else
                printf("ERROR, enter number from 1 to 7\n");
        }
        else
            printf("ERROR, enter number from 1 to 7\n");
    }
}
int getCount(int count)
{
    return count;
}

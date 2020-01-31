#include "declare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void sortByLastName(telephonebk arr_contacts[],int q,int count)
{
    int pass;
    char l1[150];
    char l2[150];
    telephonebk temp;
    for(pass=0; pass<count; pass++)
    {
        for(q=0; q<count-1; q++)
        {
            for(int i = 0; i<strlen(arr_contacts[q].last_name)+1; i++)
            {
                l1[i] = tolower(arr_contacts[q].last_name[i]);
            }
            for(int i = 0; i<strlen(arr_contacts[q+1].last_name)+1; i++)
            {
                l2[i] = tolower(arr_contacts[q+1].last_name[i]);
            }
            if(strcmp(l1,l2)==1)
            {
                temp = arr_contacts[q+1];
                arr_contacts[q+1]=arr_contacts[q];
                arr_contacts[q]=temp;
            }
        }
    }
}


void sortByBirthDay(telephonebk arr_contacts[],int q,int count)
{
    int pass;
    telephonebk temp;
    for(pass=1; pass<count; pass++)
    {
        for(q=0; q<count-1; q++)
        {
            if(arr_contacts[q].brthdt.year>arr_contacts[q+1].brthdt.year)
            {
                temp = arr_contacts[q];
                arr_contacts[q]=arr_contacts[q+1];
                arr_contacts[q+1]=temp;
            }
            if(arr_contacts[q].brthdt.year==arr_contacts[q+1].brthdt.year)
            {
                if(arr_contacts[q].brthdt.month>arr_contacts[q+1].brthdt.month)
                {
                    temp = arr_contacts[q];
                    arr_contacts[q]=arr_contacts[q+1];
                    arr_contacts[q+1]=temp;
                }
                else if(arr_contacts[q].brthdt.month==arr_contacts[q+1].brthdt.month)
                {
                    if(arr_contacts[q].brthdt.day>arr_contacts[q+1].brthdt.day)
                    {
                        temp = arr_contacts[q];
                        arr_contacts[q]=arr_contacts[q+1];
                        arr_contacts[q+1]=temp;
                    }
                }
            }
        }
    }
}


void pSort(telephonebk arr_contacts[],int q,int count)
{
    while(1)
    {
        printf("\n1. Choose 1 to sort by BirthDay\n2. Choose 2 to Sort By Name\n");
        char operation[50];
        scanf(" %s",operation);
        int len = strlen(operation);
        if(len == 1)
        {
            char newoper[1];
            strcpy(newoper,operation);
            if(strcmp(newoper,"1")==0)
            {
                sortByBirthDay(arr_contacts,q,count);
                for(q=0; q<count; q++)
                {
                    contentPrint(arr_contacts,q);
                    printf("\n\n");
                }
                printf("Number of contacts are :: %d\n",count);
                break;
            }
            else if(strcmp(newoper,"2")==0)
            {
                sortByLastName(arr_contacts,q,count);
                for(q=0; q<count; q++)
                {
                    contentPrint(arr_contacts,q);
                    printf("\n\n");
                }
                printf("Number of contacts are :: %d\n",count);
                break;
            }
            else
            {
                printf("\n1. Choose 1 to sort by BirthDay\n2. Choose 2 to Sort By Name\n");
            }
        }
        else
        {
            printf("\n1. Choose 1 to sort by BirthDay\n2. Choose 2 to Sort By Name\n");
            scanf(" %s",operation);
        }
    }
}

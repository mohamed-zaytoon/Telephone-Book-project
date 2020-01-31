#include "declare.h"
#include "check.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void add (telephonebk arr_contacts[],int count)
{
    char email[200];
    do{
        printf("enter first name\n");
        scanf(" %[^\n]s", arr_contacts[count].first_name);
    }while (!checkName(arr_contacts[count].first_name));
    do{
        printf("enter last name\n");
        scanf(" %[^\n]s", arr_contacts[count].last_name);
    }while (!checkName(arr_contacts[count].last_name));
    getDate(arr_contacts, count);
    do{
        printf("enter address\n");
        scanf(" %[^\n]s", arr_contacts[count].address);
    }while(!checkAddrs(arr_contacts[count].address));
    printf("enter e-mail\n");
    scanf("%s", email);
    while(checkEmail(email)==0){
            printf("ENTER VALID EMAIL \n");
            scanf("%s",email);
            //checkEmail(email);
    }
    strcpy(arr_contacts[count].e_mail,email);
    do{
        printf("enter number\n");
        scanf(" %[^\n]s", arr_contacts[count].number);
    }while (!checkNum(arr_contacts[count].number));
    count++;
    getContent(arr_contacts,count);
}
void getDate(telephonebk arr_contacts[], int count)
{
    char day[3];
    char mon[3];
    char year[5];
    printf("enter birth date\n");
    printf("enter day\n");
    scanf(" %s", day);
    while(!checkLttrs(day))
    {
        printf("enter day numbers\n");
        scanf(" %s", day);
    }
    printf("enter month\n");
    scanf(" %s", mon);
    while(!checkLttrs(mon))
    {
        printf("enter month in numbers\n");
        scanf(" %s", mon);
    }
    printf("enter year\n");
    scanf(" %s", year);
    while(!checkLttrs(year))
    {
        printf("enter year in numbers\n");
        scanf(" %s", year);
    }
    sscanf(year, "%d", &arr_contacts[count].brthdt.year);
    sscanf(mon, "%d", &arr_contacts[count].brthdt.month);
    sscanf(day, "%d", &arr_contacts[count].brthdt.day);
    while(!checkDate(&arr_contacts[count].brthdt.day, &arr_contacts[count].brthdt.month, &arr_contacts[count].brthdt.year))
     {
        getDate(arr_contacts, count);
     }
}

#include "declare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void modify(telephonebk arr_contacts[],int q,int count)
{
    char LN[150];
    telephonebk a[100];
    int i = 0;
    int j;
    int k[100];
    do{
        printf("enter last name\n");
        scanf(" %[^\n]s", LN);
    }while (!checkName(LN));
    for (q = 0; q < count; q++)
    {
        if(!strcasecmp(arr_contacts[q].last_name, LN))
        {
            a[i] = arr_contacts[q];
            k[i]=q;
            i++;
        }
    }
    if (!i)
    {
        printf("THIS CONTACT DON'T EXIT\n");
        return;
    }
    j = i;
    while(i--)
    {
        printf("%d.\tfirst name : %s\n",i, a[i].first_name);
        printf("  \tlast name : %s\n  \tbirth date : %d - %d - %d\n", LN, arr_contacts[i].brthdt.day, arr_contacts[i].brthdt.month, arr_contacts[i].brthdt.year);
        printf("  \taddress : %s\n  \te_mail : %s\n  \tnumber : %s\n", arr_contacts[i].address, arr_contacts[i].e_mail, arr_contacts[i].number);
    }
    int read;
    char read_s[2];
    do{
         printf("choose contact:\n");
        scanf(" %[^\n]s", read_s);
    }while (!checkNumModify(read_s));
    sscanf(read_s,"%d", &read);
    while (!(read <= j) || !(read >= 0))
    {
        printf("ENTER VALID NUMBER \n");
        scanf("%d", &read);
    }
    if(0<=read<=j)
    {
        printf("\tfirst name : %s\n", a[read].first_name);
        printf("\tlast name : %s\n\tbirth date : %d - %d - %d\n", LN, arr_contacts[read].brthdt.day, arr_contacts[read].brthdt.month, arr_contacts[read].brthdt.year);
        printf("\taddress : %s\n\te_mail : %s\n\tnumber : %s\n", arr_contacts[read].address, arr_contacts[read].e_mail, arr_contacts[read].number);
        char email[200];
    do{
        printf("enter first name\n");
        scanf(" %[^\n]s", arr_contacts[k[read]].first_name);
    }while (!checkName(arr_contacts[k[read]].first_name));
    do{
        printf("enter last name\n");
        scanf(" %[^\n]s", arr_contacts[k[read]].last_name);
    }while (!checkName(arr_contacts[k[read]].last_name));
    getDate(arr_contacts, k[read]);
    do{
        printf("enter address\n");
        scanf(" %[^\n]s", arr_contacts[k[read]].address);
    }while(!checkAddrs(arr_contacts[k[read]].address));
    printf("enter e-mail\n");
    scanf("%s", email);
    while(checkEmail(email)==0){
            printf("Enter Valid Email \n");
            scanf("%s",email);
            checkEmail(email);
    }
    strcpy(arr_contacts[k[read]].e_mail,email);
    do{
        printf("enter number\n");
        scanf(" %[^\n]s", arr_contacts[k[read]].number);
    }while (!checkNum(arr_contacts[k[read]].number));
    }
    else printf("NOT VALID CHOICE\N");
}
void getDateModify(telephonebk arr_contacts[], int count)
{
    char day[3];
    char mon[3];
    char year[5];
    printf("enter birth date\n");
    printf("enter day\n");
    scanf(" %s", day);
    while(!checkLttrs(day))
    {
        printf("ENTER DAY IN NUMBER\n");
        scanf(" %s", day);
    }
    printf("enter month\n");
    scanf(" %s", mon);
    while(!checkLttrs(mon))
    {
        printf("ENTER MONTH IN NUMBER\n");
        scanf(" %s", mon);
    }
    printf("enter year\n");
    scanf(" %s", year);
    while(!checkLttrs(year))
    {
        printf("ENTER YEAR IN NUMBERS\n");
        scanf(" %s", year);
    }
    sscanf(year, "%d", &arr_contacts[count].brthdt.year);
    sscanf(mon, "%d", &arr_contacts[count].brthdt.month);
    sscanf(day, "%d", &arr_contacts[count].brthdt.day);
    while(!checkDate(&arr_contacts[count].brthdt.day, &arr_contacts[count].brthdt.month, &arr_contacts[count].brthdt.year))
     {
        getDateModify(arr_contacts, count);
     }
}
void checkNumModify(char s[])
{
    for (int i=0; i < strlen(s); i++)
    {
        if(!isdigit(s[i]))
        {
            printf("USE ONLY DIGITS\N");
            return 0;
        }
    }
    return 1;
}

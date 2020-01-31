#ifndef check_h
#define check_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int checkEmail(char st[])
{
    int len = strlen(st)+1;
    int i;
    int dotcom=0,ats=0,coma=0;
    char com[5];
    int n = len-5;
    for(i=0; i<5; i++)
    {
        com[i]=st[n];
        n++;
    }
    if(strcmp(com,".com")==0)
    {
        dotcom++;
    }
    for(i=0; i<len; i++)
    {
        if(st[i]=='@')
        {
            ats++;
        }
        if(st[i]==',')
        {
            coma++;
        }
    }

    if(dotcom!=1 || ats !=1 &&coma==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int checkDate(int* day, int* mon, int* year)
{
    if(*year > 2100 || *year <1900)
    {
        printf("INVALID YEAR\n");
        return 0;
    }
    if(*mon > 12 || *mon < 1)
    {
        printf("INVALID MONTH\n");
        return 0;
    }
    if(*day < 1 || *day > 31)
    {
        printf("INVALID DAY\n");
        return 0;
    }
    if(*day > 30 && (*mon == 4 || *mon == 6 || *mon == 9 || *mon == 11))
    {
        printf("INVALID DAY IN THIS MONTH\n");
        return 0;
    }
    if(*day >= 29 && *mon == 2 && !(*year%400==0 ||(*year%4==0 && *year%100!=0)))
    {
        printf("INVALID DAY IN THIS MONTH IN THIS YEAR\n");
        return 0;
    }
    return 1;
}
int checkLttrs(char s[])
{
    int i = 0;
    for (; i < strlen(s); i++)
    {
        if(!isdigit(s[i])) return 0;
    }
    return 1;
}
int checkNum(char s[])
{
    if (strlen(s)>15)
    {
        printf("TOO LONG NUMBER\n");
        return 0;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if(!isdigit(s[i]))
        {
            if (s[i]=='-'&&(i<4 && i>1)) continue;
            else
            {
                printf("USE ONLY DIGTITS OR '-' \n");
                return 0;
            }
        }
    }
    return 1;
}
int checkName(char s[])
{
    if (strlen(s)>35)
    {
        printf("TOO LONG NAME\n");
        return 0;
    }
    for (int i = 0; i < strlen(s); i++)
    {
        if(!isalpha(s[i]))
        {
            printf("USE ONLY LETTERS\n");
            return 0;
        }
    }
    return 1;
}
int checkAddrs(char s[])
{
    if (strlen(s)>85)
    {
        printf("TOO LONG ADDRESS\n");
        return 0;
    }
    for(int i = 0; i < strlen(s); i++)
    {
        if(isalpha(s[i]))continue;
        else if (isdigit(s[i]))continue;
        else if (s[i] == ' ')continue;
        else if (s[i]=='.')continue;
        else
        {
            printf("USE LETTERS, DIGITS AND SPACES ONLY\n");
            return 0;
        }
    }
    return 1;
}
#endif


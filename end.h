#ifndef end_h
#define end_h
void end(telephonebk arr_contacts[],int q,int count)
{
    int res;
    printf("if you didn't save all data will be discarded\n1.save\n2.exit\n");
    scanf("%d", &res);
    if(res == 1)
        {
         saveToFile(arr_contacts,q,count);
         exit(0);
        }
    else if (res == 2)
        exit(0);
    else
    {
        printf("wrong number\n");
        return end(arr_contacts,q,count);
    }
}
#endif

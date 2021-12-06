#include<stdio.h>
int main()
{
    int n,i,initial,day,copy_initial,amount,remainder;
    int socks=0,total_socks,day_without_socks;
    scanf("%d %d",&initial,&day);
    copy_initial=initial;
    while(initial>0)             //if i didn't give the second condition loop would never stop cause always 1 remainder will be left.
    {
        amount=initial/day;
        remainder=initial%day;
        initial=remainder+amount;
        socks=socks+amount;
        if(initial<day)
        {
            break;
        }

    }
    total_socks=copy_initial+socks;
    printf("%d\n",total_socks);
    return 0;
}

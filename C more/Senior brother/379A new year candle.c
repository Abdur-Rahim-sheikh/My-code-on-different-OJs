#include<stdio.h>
int main()
{
    int n,i,candle,copy_candle,amount,remainder;
    int made_candle,hour=0,total_hour;
    scanf("%d %d",&candle,&made_candle);
    copy_candle=candle;
    while(candle>0)             //if i didn't give the second condition loop would never stop cause always 1 remainder will be left.
    {
        amount=candle/made_candle;
        remainder=candle%made_candle;
        candle=remainder+amount;
        hour=hour+amount;
        if(candle<made_candle)
        {
            break;
        }

    }
    total_hour=copy_candle+hour;
    printf("%d\n",total_hour);
    return 0;
}

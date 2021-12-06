#include<stdio.h>
int main()
{
    int cola,rem,div,n,totalcola;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            return 0;
        for(totalcola=0;n>=3;)
        {
            cola=n/3;
            n=n/3+n%3;
            totalcola=totalcola+cola;
        }
        if(n==2)
            printf("%d\n",totalcola+1);
        else
            printf("%d\n",totalcola);
    }
    return 0;
}

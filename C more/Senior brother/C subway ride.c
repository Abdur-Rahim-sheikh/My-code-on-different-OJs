#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,n,m,i,rem,sp_tk,left_tk,cost;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    cost=m*a;
    if(cost>b)
    {
        rem=n%m;
        n=n/m;
        sp_tk=n*b;
        left_tk=rem*a;
        if(left_tk>b)
            printf("%d\n",sp_tk+b);
        else
        printf("%d\n",sp_tk+left_tk);
    }
    else
    {
    left_tk=n*a;
    printf("%d\n",left_tk);
    }
    return 0;
}

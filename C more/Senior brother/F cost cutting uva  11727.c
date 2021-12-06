#include<stdio.h>
int main()
{
    int i,n,cost,a,b,c;
    scanf("%I64d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);

        if(a>b && a>c)
        {
            if(b>c)
                printf("Case %d: %d\n",i+1,b);
            else
                printf("Case %d: %d\n",i+1,c);
        }
        else if(b>a && b>c)
        {
            if(a>c)
                printf("Case %d: %d\n",i+1,a);
            else
                printf("Case %d: %d\n",i+1,c);
        }
        else
        {
            if(a>b)
                printf("Case %d: %d\n",i+1,a);
            else
                printf("Case %d: %d\n",i+1,b);
        }
    }

    return 0;
}

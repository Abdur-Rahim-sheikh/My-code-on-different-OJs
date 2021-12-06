#include<stdio.h>
int main()
{
    long long int test,n,val,i,j,clown;

    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        for(j=0;j<n;j++)
        {
            scanf("%lld",&val);
            if(j==0)
                clown=val;
            if(val>clown)
            {
                clown=val;

            }
        }
        printf("Case %lld: %lld\n",i+1,clown);

    }
    return 0;
}

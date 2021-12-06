#include<stdio.h>
int main()
{
    long long int i,j,test,n,val,mile,juice,mrate,jrate;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        for(j=0,mrate=0,jrate=0;j<n;j++)
        {
            scanf("%lld",&val);


                mile=(val/30)+1;


                juice=(val/60)+1;

                mrate=mrate+mile*10;

                jrate=jrate+juice*15;



        }

        if(mrate==jrate)
            printf("Case %lld: mile juice %lld\n",i+1,mrate);
        else if(mrate<jrate)
        {
            printf("Case %lld: mile %lld\n",i+1,mrate);

        }
        else
        {
            printf("Case %lld: juice %lld\n",i+1,jrate);
        }
    }
    return 0;
}

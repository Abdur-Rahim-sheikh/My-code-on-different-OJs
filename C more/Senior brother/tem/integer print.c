#include<stdio.h>
int main()
{
    long long int a,sum1=0,sum2=0,n,m,i,test,start,end,begin,last,tem1,tem2;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld %lld",&n,&m);
        sum1=(1+n)*n/2;
        for(begin=0,last=1;last*m<=n;begin=begin+2,last=last+2)
        {

            start=begin*m;                                ///i didnt add +1 cause i want to cut till start.
                end=last*m;
                if(start%2==1)
                    tem1=(1+start)*start/2+(1+start)/2;
                else
                    tem1=(1+start)*start/2;
                if(end%2==1)
                   tem2=(1+end)*(end/2)+(1+end)/2;
                else
                    tem2=(1+end)*end/2;
                sum2=sum2+tem2-tem1;

       /// printf("%lld %lld %lld %lld\n",sum1,sum2,tem1,tem2);
        }
        printf("%lld\n",sum1-2*sum2);
    }
    return 0;
}

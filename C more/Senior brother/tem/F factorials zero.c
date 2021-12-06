#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
static long sum=1,count,i,previous,ara[200000000];
void factorial(long n)
{
    for(i=previous+1;i<=n;i++)
    {
        sum=sum*i;
        carry=carry*i;
        while(sum%10==0)
        {
            count++;
            sum=sum/10;
        }

        ara[i]=count;
        sum=sum%1000000;
        carry=sum/1000000;
    }

    previous=n;
}
int main()
{
    long i,j,k,m,n,test,zero;
    scanf("%ld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%ld",&n);
        if(ara[n]==0)
            factorial(n);
        printf("%ld\n",ara[n]);
    }
    return 0;
}

#include<stdio.h>
int main()
{
    long long int n,val,*value,i,j,sum,rem,second_multiplyer;

    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&val);
        value=&val;
        for(j=1,sum=0;j<=val/2;j++)
        {
            rem=(*value%j);
            if(rem==0)
            {
                second_multiplyer=(*value)/j;
                if(second_multiplyer<j)
                    continue;
                if(second_multiplyer==j || second_multiplyer==val)
                    sum=sum+j;
                else
                    sum=sum+second_multiplyer+j;

            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}

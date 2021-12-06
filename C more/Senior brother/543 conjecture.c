#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int prime[10000];
long long int prime_factory(long long int n);
int main()
{
    long long int i,j,k,m,n,total,sign;
    while(1){
        scanf("%lld",&n);
            if(n==0)
                return 0;
        total=prime_factory(n);

        for(i=total/2-1,j=total/2-1,sign=0;i<total || j>=0; )
        {


                if(prime[i]+prime[j]==n)
                {
                    printf("%lld = %lld + %lld\n",n,prime[i],prime[j]);

                    break;

                }
                else if(prime[i]+prime[j]>n)
                    j--;
                else
                    i++;
        }

    }
}
// how much prime from 2 to n and what
// how much prime from 2 to n and what
long long int prime_factory(long long int n)
{
	long long int j,k,i,number[10000],total=0;

	for(i=2;i<=n;i++)
	{


		if(number[i]==1)
		continue;

		prime[total++]=i;
        //printf("%d\n",prime[total-1]);
		for(j=i*2,k=3;j<=n;k++)
		{
			//printf("%lld\n",number[j]);
			number[j]=1;
			j=i*k;

		}
	}
	return total;
}

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 1000000
int prime[N];
void prime_factory( );
int main()
{
    int i,j,k,m,n,total,sign;
    prime_factory(N);
    while(1){
        scanf("%d",&n);
            if(n==0)
                return 0;


        for(i=2,sign=0;i<n/2+1;i++ )
        {
                j=n-i;

                if(prime[i]==0 &&prime[j]==0)
                {
                    printf("%d = %d + %d\n",n,i,j);
                    sign=1;
                    break;

                }

        }
        if(sign==0)
            printf("Goldbach's conjecture is wrong.\n");
    }
}

// how much prime from 2 to n and what
void prime_factory( )
{
	int j,k,i,number;
	number=sqrt(N)+1;
	for(i=2;i<=number;i++)
	{


		if(prime[i]==1)
		continue;



		for(j=i*2,k=3;j<=N;k++)
		{

			prime[j]=1;
			j=i*k;

		}
	}

}

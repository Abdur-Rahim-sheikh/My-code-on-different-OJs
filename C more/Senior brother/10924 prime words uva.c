#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int prime_check(long long int n);
int main()
{
    long long int i,j,k,m,n,rem,div,val,previous,sum;
    char name[100];
    while(scanf("%s",name)!=EOF)
    {
        for(i=0,sum=0;name[i]!='\0';i++)
        {
            if(name[i]>='a' && name[i]<='z') sum=sum+(name[i]-'a'+1);
            else sum=sum+(name[i]-'A'+27);
        }

        //printf("%lld",sum);
        k=prime_check(sum);

        if(k==0 && sum!=1) printf("It is not a prime word.\n");
        else printf("It is a prime word.\n");
    }
    return 0;
}


//if return 1,then prime,if return 0,then not prime
int prime_check(long long int n)
	{
		int i,j,rem,sign=0;

		if(n==1) return 0;
		else if(n==2 || n==3) return 1;
		for(i=2;i<sqrt(n)+1;i++)
		{
			rem=n%i;
			if(rem==0){
               sign=1;

               return 0;
			}
		}
		if(sign==0)
		return 1;
	}

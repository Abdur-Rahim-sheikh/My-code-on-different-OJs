#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
bool prime[10000000];
void prime_factory(int n);
int main()
{
    prime_factory(10000000);
    int i,j,k,m,n,val,t=0,test;
    //scanf("%d",&test);
    while( scanf("%d",&n)!=EOF){

        val=n;
        int rev=0;
        while(n>0){
            rev+=(n%10);
            n=n/10;
            if(n>0)rev=rev*10;
        }
        printf("%d is ",val);

        if(prime[val]==0 && prime[rev]==0 && val!=rev){
            printf("emirp.\n");
        }
        else if(prime[val]==0){
            printf("prime.\n");
        }
        else printf("not prime.\n");
    }

    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(int n)
{
	prime[1]=1;
	int j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{


		if(prime[i]==1)
		continue;


        //printf("%d\n",prime[total-1]);
		for(j=i*2,k=3;j<=n;k++)
		{
			//printf("%lld\n",number[j]);
			prime[j]=1;
			j=i*k;

		}
	}

}

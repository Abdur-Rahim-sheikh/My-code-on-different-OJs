#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
bool prime[10000005];
ll primo[10000005];
ll total;
void prime_factory(long long n);
int main()
{

    ll i,j,k,m,n,val,t=0,test;

    prime_factory(10000000);

    cin>>val;
    n=val;
    for(i=0;primo[i]*primo[i]<val && i<total;i++){
            int sign=0;
        while(val%primo[i]==0)val=val/primo[i],sign=1;

        if(sign)printf("%lld\n",primo[i]);
    }
    if(val>1)printf("%lld\n",val);
    if(n==1) printf("0\n");
    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(long long n)
{
	prime[1]=1;
	ll j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{


		if(prime[i]==1)
            continue;
        else primo[total++]=i;


		for(j=i*2,k=3;j<=n;k++)
		{

			prime[j]=1;
			j=i*k;

		}
	}

}

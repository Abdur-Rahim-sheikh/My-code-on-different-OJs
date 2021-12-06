#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
bool prime[6000000];
ll arr[1000000],total;
void prime_factory(ll n);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test;

    cin>>test;
    ///As the problem described it's clear that only those base will give a trailing
    ///zeros for n whom are factor of n,,,cause if n=9 then to produce 9 in base the
    ///it will restart after 8 and will increase bit space with a zero,as well as for base 9;
    ///and no upper base of n can make it's trailing zeros.

    prime_factory(1000006);
    for(i=2;i<1000006;i++) if(prime[i]==0)arr[total++]=i;
    while(test--){
        scanf("%lld",&n);
        ll cp_n=n,sum=1;
        for(i=0,cnt=0;i<total && arr[i]<=sqrt(n);i++,cnt=0){
           // printf("%lld ",n);
            while(n%arr[i]==0)cnt++,n=n/arr[i];
            sum=sum*(cnt+1);
            //printf("%lld %lld %lld\n",n,cnt,arr[i]);
        }
        if(n>1)sum=sum*2;  ///n>1 means the current n is also a prime number
                            ///means so cnt=1 so sum=sum*(cnt+1)as we know cnt =1,so sum=sum*2;

        printf("Case %lld: %lld\n",++t,sum-1);///-1 is for 1 which can dived n but don't cause trailing zero



    }

    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(ll n)
{
	prime[1]=1;
	int j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{


		if(prime[i]==1)
		continue;


        //printf("%d\n",prime[total-1]);
		for(j=i*i;j<=n;j+=i)
		{
			//printf("%lld\n",number[j]);
			prime[j]=1;


		}
	}

}

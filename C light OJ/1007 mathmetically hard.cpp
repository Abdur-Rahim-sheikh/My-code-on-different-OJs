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
bool prime[5100000];
unsigned long long primo[5000050];
void prime_factory(ll n);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test,a,b;
    unsigned long long sum=0;

    for(i=2;i<=5000000;i++)primo[i]=i;
    prime_factory(5000001);
    for(i=2;i<5000001;i++){ sum+=(primo[i]*primo[i]);primo[i]=sum;}
    //cout<<primo[6]<<' '<<primo[8]<<endl;
    cin>>test;
    while(test--){
        scanf("%lld %lld",&a,&b);

        //for(i=a;i<=b;i++)sum+=primo[i]*primo[i];
        printf("Case %lld: %llu\n",++t,primo[b]-primo[a-1]);
    }
    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(ll n)
{

	ll j,k,i,number;
	//number=sqrt(n)+1;
	for(i=2;i<=n;i++)
	{


		if(prime[i]==1)
		continue;
        primo[i]=i-1;

        //printf("%d\n",prime[total-1]);
		for(j=i*2;j<=n;j+=i)
		{
			//printf("%lld\n",number[j]);
			prime[j]=1;
			primo[j]=primo[j]-(primo[j]/i);

		}
	}

}


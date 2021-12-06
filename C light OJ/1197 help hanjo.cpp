#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pairii pair<int,int>
using namespace std;
bool prime[200000];
void prime_factory(int n);
void segmentedSieve(ll left,ll right,vector<ll> & primo);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt,test;

    prime_factory(100000);
    vector<ll>primo;
    for(i=2;i<100000;i++)if(prime[i]==false)primo.pb(i);
    cin>>test;

    while(test--){
        scanf("%lld %lld",&m,&n);

        segmentedSieve(m,n,primo);
        ll p =n-m+1;
        for(i=0,cnt=0;i<p;i++){
            if(prime[i]==false)cnt++;
        }
        //if(m == 1)cnt--;
        printf("Case %lld: %lld\n",++t,cnt);
    }


    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(int n)
{
	memset(prime,0,n+2);
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
void segmentedSieve(ll left,ll right,vector<ll> & primo){
    memset(prime,0,right-left+5);

    for(ll i=0;primo[i]*primo[i]<=right;i++){
        ll k=primo[i];
        ll base =(left/k)*k;
        //if(base==0)base=2*primo[i];
        if(base<left)base+=k;
        //cout<<base<<' '<<primo[i]<<endl;
        for(ll j =base;j<=right;j+=k)prime[j-left]=true;
        if(base==k)prime[base-left]=false;
    }

}

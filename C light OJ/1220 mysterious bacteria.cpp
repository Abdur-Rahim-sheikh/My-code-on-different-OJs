#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
bool prime[100010];
void sieve(int n);
ll GCD(ll x,ll y);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt,test,total=0;
    sieve(100000);
    ll primo[100000];
    for(i=2;i<100000;i++)if(prime[i]==false)primo[total++]=i;
    cin>>test;
    while(test--){
        scanf("%lld",&val);
        ll diff_primes=0;
        bool negetive=0;
        ll arr[100000];
        if(val<0)val=(-val),negetive=true;
        for(i=0;primo[i]*primo[i]<=val && i<total;i++){
            cnt=0;
            while(val%primo[i]==0)val/=primo[i],cnt++;

            if(cnt)arr[diff_primes++]=cnt;
        }

        if(val>1 || i==0)arr[diff_primes++]=1;  ///using i=0 condition when input val==1 then 1=1^1 so p=1,arr[0]=1 is inserted
        ll gcd=arr[0];
        //cout<<gcd<<endl;
        for(i=1;i<diff_primes;i++)gcd=GCD(gcd,arr[i]);

        if(negetive){
            while((gcd&1) == 0)gcd/=2;
        }
        //cout<<gcd<<endl;
        printf("Case %lld: %lld\n",++t,gcd);

    }


    //free();   //if pointer array
    return 0;
}
ll GCD(ll x,ll y){
    if(y == 0)return x;
    else return GCD(y,x%y);
}
void sieve(int n){
    int i;
    prime[0]=prime[1]=true;
    int p = floor(sqrt(n));
    for(i=2;i<=p;i++){

        if(prime[i]==true) continue;
        for(int j=i*i;j<=n;j+=i) prime[j]=true;
    }
}

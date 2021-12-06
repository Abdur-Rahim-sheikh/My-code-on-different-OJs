#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll power(ll n,ll k,ll mod){
    if(k==0)return 1;
    if(k==1)return n;
    if(k%2)return ((power(n,k-1,mod)%mod)*n)%mod;
    else{
        ll p=power(n,k/2,mod)%mod;
        return (p*p)%mod;
    }
}
int main(){

    ll test,i,k,j,n,val,t=0;
    ll mod,sum;
    cin>>test;
    while(test--){
        cin>>n>>k>>mod;
        sum=0;
        for(i=0;i<n;i++)scanf("%lld",&val),sum+=val;
        sum=sum%mod;
        ll mul=(power(n,k-1,mod)*k)%mod;
        printf("Case %lld: %lld\n",++t,(mul*sum)%mod);
    }
}

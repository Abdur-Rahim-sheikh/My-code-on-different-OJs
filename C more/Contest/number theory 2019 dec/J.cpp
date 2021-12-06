#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare prllf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
//#define for(i,n) for(ll i=0;i<n;i++)
//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
// where is the prime in 2 to n and what(by index)
bool prime[40000],moded;
ll mod=1e9;
void seive(ll n)
{
	prime[1]=1;
	ll j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{
		if(prime[i]>0)
		continue;

		for(j=i*i;j<=n;j+=i) if(prime[j]==0)prime[j]=true;
	}
}
ll power(ll base,ll n){
    if(n==0)return 1LL;
    else if(n==1)return base;

    if(n&1){
        ll x=power(base,n-1)*base;
        if(x<=0 or x>=mod)moded=true;
        return (x+mod)%mod;
    }
    else{
        ll x=power(base,n/2);
        x*=x;
        if(x<=0 or x>=mod)moded=true;
        return (x+mod)%mod;
    }


}
int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(40000);
    vector<ll>primo;
    for(i=2;i<40000;i++)if(prime[i]==0)primo.pb(i);
    map<ll,ll> a,b;
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%lld",&val);
        for(j=0;primo[j]*primo[j]<=val;j++){
            cnt=0;
            while(val%primo[j]==0)cnt++,val/=primo[j];
            a[primo[j]]+=cnt;
        }
        if(val>1)a[val]+=1;
    }

    cin>>m;
    for(i=0;i<m;i++){
        scanf("%lld",&val);
        for(j=0;primo[j]*primo[j]<=val;j++){
            cnt=0;
            while(val%primo[j]==0)cnt++,val/=primo[j];
            b[primo[j]]+=cnt;
        }
        if(val>1)b[val]+=1;
    }
    map<ll,ll> :: iterator it;
    ll sum=1;
    for(it=a.begin(),moded=false;it!=a.end();it++){
        k=it->first;
        sum=sum*power(k,min(a[k],b[k]));
        if(sum<=0 or sum>=mod) moded=true;

        sum=(sum+mod)%mod;
    }
    if(moded)printf("%09lld\n",sum);
    else printf("%lld\n",sum);
    //free();   //if poller array
    return 0;
}

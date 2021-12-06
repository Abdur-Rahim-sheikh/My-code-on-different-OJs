#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("Showing %lld\n",n)
#define p2(m,n) printf("showing %lld %lld\n",m,n)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
ll power(ll n,ll k,ll mod){
    if(!k)return 1;
    ll ans =power(n,k/2,mod);
    ans=(ans*ans)%mod;
    if(k&1)ans=(ans*n)%mod;
    return ans;
}
int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        ll arr[n],mod[n];
        ll mul=1,ans=0;
        for(i=0;i<n;i++)scanf("%lld %lld",&mod[i],&arr[i]),mul*=mod[i];

        for(i=0;i<n;i++){
            ll k=mul/mod[i];
            //p2(k,mod[i]);
            //if(__gcd(k,mod[i])!=1)break;
            ans+=arr[i]*k*power(k,mod[i]-2,mod[i]);
        }

        printf("Case %lld: %lld\n",++t,ans%mul);
    }
    //free();   //if pointer array
    return 0;
}

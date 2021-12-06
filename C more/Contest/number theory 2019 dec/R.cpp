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
using namespace std;
ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int main(){
    ll i,j,k,n,m,val,test;
    //freopen("000input.txt","r",stdin);
    bool visit[6005];

    while(cin>>n){
        for(i=0;i<=n;i++)visit[i]=false;
        ll arr[n+5];

        for(i=1;i<=n;i++)scanf("%lld",&arr[i]);
        ll ans=1LL;
        for(i=1;i<=n;i++){
            ll cnt=0LL;
            if(visit[i])continue;

            while(!visit[i]){
                visit[i]=true;
                cnt++;
                i=arr[i];

            }
           ans=(ans/gcd(ans,cnt))*cnt;
        }
        printf("%lld\n",ans);
    }
    //free();   //if poller array
    return 0;
}

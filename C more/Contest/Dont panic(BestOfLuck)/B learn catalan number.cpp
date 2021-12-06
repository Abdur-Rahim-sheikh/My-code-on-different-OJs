#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;
ll Mod = 100000007;
pii extnuc(ll a, ll b){
    if(b==0)return mp(1,0);

    pii d=extnuc(b,a%b);
    return mp(d.second,(d.first-d.second*(a/b)));
}

ll inv_mod(ll n){
    pii d=extnuc(n,Mod);
    return ((d.first%Mod)+Mod)%Mod;
}

ll power[1000006],total;
void perfect_power(ll n){

    ll i,j;
    for(i=2;i*i<=n;i++){
        for(j=i*i;j<=n;j*=i)power[total++]=j;
    }
    sort(power,power+total);
    total=unique(power,power+total)-power;
    power[total]=1e12;
    return;
}
ll fact[2000006];
int main(){

    ll i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    perfect_power(1e10);
    fact[0]=fact[1]=1;
    for(i=2;i<=2000000;i++)fact[i]=(i*fact[i-1])%Mod;

    cin>>test;
    while(test--){
        scanf("%lld %lld",&k,&m);
        n=upper_bound(power,power+total,m)-power;
        n-=lower_bound(power,power+total,k)-power;

        if(n==0){
            printf("Case %lld: 0\n",++t);
            continue;
        }
        ll ans=(fact[n]*fact[n+1])%Mod;
        ans =inv_mod(ans);
        ans=(fact[2*n]*ans)%Mod;
        printf("Case %lld: %lld\n",++t,ans);
    }
    //free();   //if pointer array
    return 0;
}

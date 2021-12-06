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
vector<ll> subset;
ll arr[30],sum;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void solve(int i,int n,ll val){
    if(i==n){
        int k,len=subset.size();
        ll mul=1;

        for(k=0;k<len;k++){
            mul=(mul*subset[k])/gcd(mul,subset[k]);
            if(mul>val)break;
        }

        if(k==len && len>0){
            if(len&1)sum+=(val/mul);
            else sum-=(val/mul);
        }
        return;
    }
    solve(i+1,n,val);
    subset.pb(arr[i]);
    solve(i+1,n,val);
    subset.pop_back();
    return;


}
int main(){

    ll i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%lld %lld",&val,&n);
        for(i=0;i<n;i++)scanf("%lld",&arr[i]);
        subset.clear();
        sum=0;
        solve(0,n,val);
        printf("Case %lld: %lld\n",++t,val-sum);
    }
    //free();   //if pointer array
    return 0;
}

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

///If n=(2^i)*(k^2) then fi(n) is odd magic
///let p=k*k/// all odd k will be taken
vector<ll> values;

void solve(ll n){

    ll i,k,p;
    for(k=1;k*k<=n;k+=2){
        p=k*k;
        for(i=1;i*p<=n;i=i<<1){  ///I will increase as power of 2
            values.pb(i*p);
        }
    }
    sort(values.begin(),values.end());
    return;
}
ll bs(ll n){
    ll hi=values.size(),lo=0,mid;
    while(hi>=lo){
        mid = (hi+lo)/2;

        if(values[mid]>n && values[mid-1]<=n)break;
        else if(values[mid]>n)hi = mid-1;
        else lo=mid+1;
    }
    return mid;
}
int main(){

    ll i,j,k,m,n,val,t=0,cnt,test;
    solve(1e12);
    //freopen("000input.txt","r",stdin);
    cin>>test;

    while(test--){
        scanf("%lld",&val);
        printf("Case %lld: %lld\n",++t,val-bs(val));
    }
    //free();   //if pointer array
    return 0;
}

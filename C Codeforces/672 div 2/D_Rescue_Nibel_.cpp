#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
using namespace std;
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
    cerr << ' ' << H;
     dbg_out(T...); 
}
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')'<<':', dbg_out(__VA_ARGS__)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll mod=998244353;

ll modinv(ll x,ll n){
    if(n==1)return x;
    ll ans=modinv(x,n/2);
    ans=(ans*ans)%mod;
    if(n&1)ans=(ans*x)%mod;
    return ans;
}
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    fastIO
    test=1;
    vll fact(300005);
    fact[0]=fact[1]=1;
    for(i=2;i<300005;i++)fact[i]=(fact[i-1]*i)%mod;
    while(test--){
        cin>>n>>k;
        map<ll,ll> maped;
        vector<pii> arr(n);
        for(i=0;i<n;i++){
            cin>>j>>m;
            maped[j]=1;
            maped[m]=1;
            arr[i]={j,m};
        }
        int cnt=0;
        for(auto &u: maped)  u.second = cnt++;
        

        vll csum(2*n+1,0);
        for(i=0;i<n;i++){
            ll x= arr[i].first,y=arr[i].second;
            csum[maped[x]]++;
            csum[maped[y]+1]--;
        }
        for(i=1;i<2*n;i++)csum[i]+=csum[i-1];
        //dbg(csum);
        ll ans=0;
        for(i=0;i<2*n;i++){
            if(csum[i]>=k){
                ll x=csum[i];
                //dbg(x,fact[k],fact[x-k]);
                ll tem=modinv((fact[k]*fact[x-k])%mod,mod-2);
                ans=(ans+tem*fact[x])%mod;
            }
        }
        cout<<ans<<endl;
    }
    //free();   //if pointer array
    return 0;
}

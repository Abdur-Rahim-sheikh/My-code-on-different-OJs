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
        return os << '(' << p.first <<gap<<','<< gap << p.second << ')';
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
ll mod =(1e9)+7;
ll power(ll x,ll p){
    if(p==0)return 1;
    ll ans = power(x,p/2);
    ans =(ans*ans+mod)%mod;
    if(p&1)ans=(ans*x+mod)%mod;
    return ans;
}
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    ll max=200005;
    
    vll fact(max);
    fact[0]=fact[1]=1;
    for(i=2;i<max;i++)fact[i]=(fact[i-1]*i)%mod;
    while(test--){
        cin>>n>>m>>k;
        vll arr(n);
        for(auto &u: arr)cin>>u;
        sort(all(arr));
        ll count=0;
        m--;
        for(i=0;i+m<n;i++){
            ll p = arr[i]+k;
            ll last=i;
            for(ll x=n-1-i;x>0;x=x>>1){
                while((last+x)<n and arr[last+x]<=p)
                    last+=x;
            }
            ll pair = last-i;
            
            if(pair<m)continue;
            
            ll deno = (fact[m]*fact[pair-m]+mod)%mod;

            count=(count+fact[pair]*power(deno,mod-2)+mod)%mod;
        }
        cout<<count<<endl;
    }
    //free();   //if pointer array
    return 0;
}

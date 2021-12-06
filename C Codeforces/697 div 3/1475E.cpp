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
ll mod = 1e9 + 7;

ll power(ll x, ll n){
    if(n==1)return x;
    ll val = power(x,n/2);
    val = (val*val)%mod;
    if(n&1)val=(val*x)%mod;
    return val;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;

    vll fact(1001);
    fact[0]=fact[1]=1;
    for(i=2;i<1001;i++)fact[i]=(fact[i-1]*i)%mod;
    while(test--){
        cin>>n>>k;
        vi arr(n);
        for(auto &u: arr)cin>>u;
        sort(all(arr),greater<int>());
        int x = arr[k-1];
        int p=0,q=0;
        int cnt=k-1;
        while(cnt>=0 and arr[cnt--]==x)q++;
        cnt = k;
        while(cnt<n and arr[cnt++]==x)p++;

        
        ll denom = power((fact[p]*fact[q])%mod,mod-2);
        //dbg(denom,fact[p],fact[q],fact[p+q]);
        cout<<(fact[p+q]*denom)%mod<<endl;

    }
    //free();   //if pointer array
    return 0;
}

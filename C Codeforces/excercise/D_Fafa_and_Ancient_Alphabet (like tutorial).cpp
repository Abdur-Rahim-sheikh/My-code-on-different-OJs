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
#define vll vector<ll>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll mod = 1e9 + 7;
ll inv(ll x,ll n){
    if(n==1)return x;
    ll ans=inv(x,n/2);
    ans=(ans*ans)%mod;
    if(n&1)ans=(ans*x)%mod;
    return ans;
}
ll update(ll nomi,ll deno){
    return (nomi*inv(deno,mod-2))%mod;
}
int main(){
    ll i,j,k,n,m,val,t=0,test;
    fastIO
    //freopen("000input.txt","r",stdin);
    cin>>n>>m;
    ll prob=0;

    vll arr(n),brr(n);
    for(auto &u : arr)cin>>u;
    for(auto &u : brr)cin>>u;
    //getting new probability divides old probability
    for(i=n-1;i>=0;i--){
        if(arr[i]==0 and brr[i]==0){
            //(m-1)/2*m + prob/m
            prob=update(m-1+2*prob,2*m);
        }
        else if(arr[i]==0){
            //(m-brr[i])/m + prob/m
            
            prob=update(m-brr[i]+prob,m);
        }
        else if(brr[i]==0){
            //(arr[i]-1)/m + prob/m
            prob=update(arr[i]-1+prob,m);
        }
        else if(arr[i]>brr[i]){
            //1/np
            prob=1LL;
        }
        else if(arr[i]<brr[i]) prob=0ll;
    }
    cout<<prob<<endl;
    //free();   //if pointer array
    return 0;
}

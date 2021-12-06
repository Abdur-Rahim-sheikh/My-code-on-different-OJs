#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
// #define mod 1000000007
#define ll long long
#define endl '\n'
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
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<ll>
#define vvi vector<vi>
#define vll vector<ll>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//replace less<ll> to less_equal<ll> to take duplicate values


ll dp[201][21][11],mod,n,allowed;
vll arr;

ll recurse(ll pos,ll rem,ll taken){
    if(taken==allowed){
        if(!rem)return 1;
        return 0;
    }
    if(pos==n)return 0;

    if(dp[pos][rem][taken]!=-1)return dp[pos][rem][taken];
    ll newReminder = (((rem+arr[pos])%mod)+mod)%mod;
    return dp[pos][rem][taken] = recurse(pos+1,rem,taken)+recurse(pos+1,newReminder,taken+1);
}
int main(){
    ll i,j,k,m,val,t=0,test,q;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>q;
        arr.clear();
        arr.resize(n);
        for(ll &u: arr)scanf("%lld",&u);

        // for(ll div=1;div<=20;div++){
        //     for(ll mod=0;mod<div;mod++){
        //         for()
        //     }
        // }

        // It seems implementing recursion would be easy!

        printf("Case %lld:\n",++t);
        while(q--){
            scanf("%lld %lld",&mod,&allowed);
            memset(dp,-1,sizeof(dp));
            printf("%lld\n",recurse(0,0,0));
        }
    }
    //free();   //if pointer array
    return 0;
}

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define mod 1000000007
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
//replace less<int> to less_equal<int> to take duplicate values
vector<pii> wing;
vector<ll> dp[2];
vvi tree;

void solve(int n,int pa=0){
    for(int u: tree[n]){
        if(u==pa)continue;
        solve(u,n);
        dp[0][n]+=max(abs(wing[n].x-wing[u].x)+dp[0][u],abs(wing[n].x-wing[u].y)+dp[1][u]);
        dp[1][n]+=max(abs(wing[n].y-wing[u].x)+dp[0][u],abs(wing[n].y-wing[u].y)+dp[1][u]);
    }
}

void init(){
    wing.clear();
    tree.clear();
    dp[0].clear();
    dp[1].clear();
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        init();
        wing.pb({0,0});
        dp[0].resize(n+1,0);
        dp[1].resize(n+1,0);
        tree.resize(n+1);
        for(i=0;i<n;i++){
            scanf("%d %d",&j,&k);
            wing.pb({j,k});             
        }
        ll a,b;
        for(i=1;i<n;i++){
            scanf("%lld %lld",&a,&b);
            tree[a].pb(b);
            tree[b].pb(a);
        }
        //dbg(dp[0],dp[1]);
        solve(1);
        cout<<max(dp[0][1],dp[1][1])<<endl;
    }
    //free();   //if pointer array
    return 0;
}

//IncubatorMan
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
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
#ifdef KAMOL
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')'<<':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long 
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(),(x).end()
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng((uint_fast32_t)chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
vvi G;
//Came Up with a simple Idea.
vi dis;
int dia = -1;
int root = -1;
void dfs(int src, int par = -1){
  if(dis[src]>dia){
    dia = dis[src];
    root = src;
  }
  for(int child : G[src]){
    if(child == par) continue;
    dis[child] = 1 + dis[src];
    dfs(child,src);
  }
}
void init(){
  G.clear();
  dis.clear();
  root = -1;
  dia = -1;
}
void solve(){
  init();
  int n;
  cin>>n;
  int a,b,da,db;
  cin>>a>>b>>da>>db;
  a--;
  b--;
  G.resize(n);
  for(int i=1;i<n;i++){
    int x,y;
    cin>>x>>y;
    --x;
    --y;
    G[x].pb(y);
    G[y].pb(x);
  }
  dis.resize(n);
  dis[a]=0;
  dfs(a);
  if(dis[b]<=da){
    cout<<"Alice\n";
    return;
  }
  dis.clear();
  dis.resize(n);
  dis[root]=0;
  dfs(root);
  if(dia>2*da && db>2*da) cout<<"Bob\n";
  else cout<<"Alice\n";

}

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int test=1;
  cin>>test;
  while(test--){
  solve();
    }
return 0;
}
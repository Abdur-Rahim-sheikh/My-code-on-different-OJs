#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
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
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
#define vi vector<int>
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};

//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vector<ll>edge,cnt;
vector<vi> arr;
 ll mod = (1e9) + 7;
void dfs(int n,int pa=-1){
    cnt[n]=1;
    for(int x:arr[n]){
        if(x==pa)continue;
        dfs(x,n);
        cnt[n]+=cnt[x];
    }
}
void rootChange(int n,int k){
    cnt[n]-=cnt[k];
    cnt[k]+=cnt[n];
}
void dfsDp(int n,int pa=-1){
    for(int x:arr[n]){
        if(x==pa)continue;
        edge.pb((cnt[n]-cnt[x])*cnt[x]);
        rootChange(n,x);
        dfsDp(x,n);
        rootChange(x,n);
    }
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        edge.clear();
        arr.clear();
        cnt.clear();
        arr.resize(n+1);
        cnt.resize(n+1);
        for(i=1;i<n;i++){
            scanf("%d %d",&j,&k);
            arr[j].pb(k);
            arr[k].pb(j);
        }
        dfs(1);
        dfsDp(1);
        cin>>m;
        vector<ll> values(m);
       
        for(auto &u:values)cin>>u;
        while(m<n-1)values.pb(1LL),m++;
        sort(all(values));
        ll x=1LL;
        while(m>=n-1){
            x=(x*values.back()+mod)%mod;
            values.pop_back();
            m--;
        }
        values.pb(x);
        sort(all(edge));
        ll ans=0;
        dbg(edge);
        dbg(values);
        for(i=n-2;i>=0;i--){
            ans=(ans+edge[i]*values[i])%mod;
        }
        cout<<ans<<endl;

    }
    //free();   //if pointer array
    return 0;
}

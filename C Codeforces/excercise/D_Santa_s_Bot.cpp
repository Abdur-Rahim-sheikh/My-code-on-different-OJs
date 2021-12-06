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
int mod = 998244353;
int pow(int m,int n){
    if(n==1)return m;
    int ans=pow(m,n/2);
    ans=(ans*1ll*ans)%mod;
    if(n&1)ans=(ans*1ll*m)%mod;
    return ans;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    fastIO
    cin>>n;
    vi arr[n],cnt(1e6+1,0),inv(1e6+1);
    for(i=0;i<n;i++){
        cin>>m;
        arr[i].resize(m);

        for(j=0;j<m;j++){
            cin>>arr[i][j];
            cnt[arr[i][j]]++;
        }
    }
    for(i=1;i<=1e6;i++)inv[i]=pow(i,mod-2);
    int ans=0;
    for(i=0;i<n;i++){
        for(auto u: arr[i]){
            int tem=(inv[n]*1ll*inv[n])%mod;
            tem=(tem*1ll*inv[arr[i].size()])%mod;
            ans=(ans+cnt[u]*1ll*tem)%mod;
        }
    }
    cout<<ans<<endl;
    //free();   //if pointer array
    return 0;
}

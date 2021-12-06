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
#define mx(a,b) a=max(a,b);
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n>>m>>k;
    vi arr[3];
    arr[0].resize(n);
    arr[1].resize(m);
    arr[2].resize(k);

    for(int &u: arr[0])cin>>u;
    for(int &u: arr[1])cin>>u;
    for(int &u: arr[2])cin>>u;

    sort(all(arr[0]),greater<int>());
    sort(all(arr[1]),greater<int>());
    sort(all(arr[2]),greater<int>());
   
    int ans=0;
    vector<vector<vi>> dp(n+1,vector<vi>(m+1,vi(k+1,0)));
    for(i=0;i<n+1;i++){
        for(j=0;j<m+1;j++){
            for(int p=0;p<k+1;p++){
                if(i<n and j<m){
                    mx(dp[i+1][j+1][p],dp[i][j][p]+arr[0][i]*arr[1][j]);
                }
                if(i<n and p<k){
                    mx(dp[i+1][j][p+1],dp[i][j][p]+arr[0][i]*arr[2][p]);
                }
                if(j<m and p<k){
                    mx(dp[i][j+1][p+1],dp[i][j][p]+arr[1][j]*arr[2][p]);
                }
                mx(ans,dp[i][j][p]);
            }
        }
    }
    cout<<ans<<endl;
    //free();   //if pointer array
    return 0;
}

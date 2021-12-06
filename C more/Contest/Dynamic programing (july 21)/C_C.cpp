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

int main(){
    int i,j,k,n,m,w,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>w>>k;
        vvi dp(n,vi(k+1));
        vi arr(n),range(n,0);
        for(int &u: arr)scanf("%d %d",&i,&u);
        sort(all(arr));
        for(i=0;i<n;i++){
            int dust=i;
            while(dust>=0 and arr[i]-arr[dust]<=w) dust--;
            range[i]=i-dust;        //i=0, dust=-1 so range[0]=1, okhe?
        }
        // dbg(range);
        // if i had swept my last brush to i'th index dust,
        // then in j'th move how much dust could i replace?
        
        for(i=0;i<n;i++){
            for(j=1;j<=k;j++){
                if(i>=range[i])dp[i][j] = max(dp[i-range[i]][j-1]+range[i],dp[i-1][j]);
                else dp[i][j]=range[i];
            }
        }
        // dbg(dp);
        printf("Case %d: %d\n",++t,dp[n-1][k]);
    }
    //free();   //if pointer array
    return 0;
}

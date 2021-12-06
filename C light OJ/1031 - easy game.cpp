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
vvi dp;
int main(){
    int i,j,k,n,m,val,t=0,test,p;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        vi arr(n);
        for(int &u: arr)cin>>u;
        dp.clear();
        dp.resize(n,vi(n,0));

        for(i=0;i<n;i++)dp[i][i]=arr[i];
        for(i=1;i<n;i++)arr[i]+=arr[i-1];
        for(i=0;i<n;i++){   
            for(j=i+1,p=0;j<n;j++,p++){
                if(p==0)dp[p][j] = arr[j];
                else dp[p][j] = arr[j]-arr[p-1];

                for(k=p;k<j;k++){
                    int a = arr[k]-(p>0?arr[p-1]:0);
                    int b = arr[j]-arr[k];
                    dp[p][j] = max(dp[p][j],max(a - dp[k+1][j], b - dp[p][k]));
                }
                // dbg(p,j,dp[p][j]);
            }
        }

        printf("Case %d: %d\n",++t,dp[0][n-1]);
    }
    //free();   //if pointer array
    return 0;
}

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
void solve(int n,int m,int i,int j,vector<vi> & ans){
    int a=i+1,b=j,c=i,d=j+1;

    if(a==n)a-=2;
    if(d==m)d-=2;
    //(a,b)(c,d),(i,j)
    //vi tem = 
    ans.pb(vi{a,b,c,d,i,j});
    //(a,b)(a,d)(i,j)
    ans.pb(vi{a,b,a,d,i,j});
    //(a,d)(c,d)(i,j)
    ans.pb(vi{a,c,i,d,d,j});
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m;
        vector<string> arr(n);
        vector<vi> ans;
        for(auto &u: arr)cin>>u;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(arr[i][j]=='1'){
                    solve(n,m,i,j,ans);
                }
            }
        }
        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++){
            for(auto u: ans[i])cout<<u+1<<' ';
            cout<<endl;
        }
    }
    //free();   //if pointer array
    return 0;
}

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
vll sum,maxi,values;
vector<vector<int>> arr;
int DFS(int n){
    sum[n]=values[n];
    if(arr[n].size()==0){
        maxi[n]=sum[n];
        return 1;
    }
    int child=0;
    for(auto &u: arr[n]){
        child+=DFS(u);
        maxi[n]=max(maxi[n],maxi[u]);
        sum[n]+=sum[u];
    }
    //dbg(child,n);
    maxi[n]=max(maxi[n],(sum[n]+child-1)/child);
    //dbg(child,maxi[n],sum[n]);
    return child;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    sum.resize(n,0);
    maxi.resize(n,0);
    values.resize(n);
    arr.resize(n);
    for(i=1;i<n;i++){
        cin>>val;
        val--;
        arr[val].pb(i);
    }
    for(auto &u: values)cin>>u;
    //dbg(values);
    DFS(0);
    cout<<maxi[0]<<endl;
    //free();   //if pointer array
    return 0;
}

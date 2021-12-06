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
bool checked[200005];
int level[200005];
queue<int>que;
vvi arr;
void BFS(int node){
    checked[node]=true;
    level[node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=arr[n].size();
        for(int i=0;i<len;i++){
            int val=arr[n][i];
            if(checked[val]==false){
                checked[val]=true;
                level[val]=level[n]+1;
                que.push(val);
            }
        }
    }
}
ll BFS2(int node,int len){
    vll path(len+1,0);
    for(int i=0;i<=len;i++)checked[i]=false;
    path[1] = 1;
    checked[1]=true;
    que.push(node);
    while(!que.empty()){
        int n = que.front();
        que.pop();
        //dbg(n,path[n]);
        for(int val: arr[n]){
            if(level[val]==level[n]+1){
                path[val]=(path[val]+path[n])%mod;
                
                if(checked[val]==false)que.push(val);
                checked[val]=true;
            }
        }
    }
    return path[len];
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n>>m;
    
    arr.resize(n+1);
    for(i=0;i<m;i++){
        cin>>j>>k;
        arr[j].pb(k);
        arr[k].pb(j);
    }
    BFS(1);

    ll ans = BFS2(1,n);
    cout<<ans<<endl;
    //free();   //if pointer array
    return 0;
}

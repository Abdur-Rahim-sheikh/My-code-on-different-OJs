#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
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
int row[8]={0,-1,0,1,1,-1,-1,1};
int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
map<pii,bool> checked;

queue<pii>que;
vector<string> s;
bool valid(pii node){
    if(node.x>=0 and node.x<s.size() and node.y>=0 and node.y<s[0].size() and s[node.x][node.y]=='-')return true;
    return false;
}
void BFS(pii node){
    checked[node]=true;
    
    que.push(node);
    while(!que.empty()){
        pii n=que.front();
        que.pop();
        
        for(int i=0;i<4;i++){
            pii tem;
            tem.x=n.x+row[i],tem.y=n.y+col[i];
            if(!valid(tem))continue;
            
            if(checked[tem]==false){
                checked[tem]=true;
                
                que.push(tem);

            }
        }
    }
}

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    while(cin>>n>>m){
        s.clear();
        checked.clear();
        s.resize(n);
        for(auto &u: s)cin>>u;
        int cnt=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(s[i][j]=='-' and checked[{i,j}]==false){
                    BFS({i,j});
                    cnt++;
                }
            }
        }
        printf("Case %d: %d\n",++t,cnt);
    }
    
    
    //free();   //if pointer array
    return 0;
}

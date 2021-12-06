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
vector<string> ss;

int BFS(pii node,char alpha){
    checked[node]=true;
    
    que.push(node);
    int cnt=0;
    while(!que.empty()){
        pii n=que.front();
        que.pop();
        cnt++;
        for(int i=0;i<4;i++){
            pii val;
            val.x=n.x+row[i];
            val.y=n.y+col[i];
            if(val.x<0 or val.x>=ss.size() or val.y<0 or val.y>=ss[0].size())continue;
            
            if(checked[val]==false and ss[val.x][val.y]==alpha){
                checked[val]=true;
                que.push(val);
            }
        }
    }
    return cnt;
}
bool comp(pii a,pii b){
    if(a.x>b.x)return true;
    else if(a.x==b.x and a.y<b.y)return true;
    return false;
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    while(true){
        cin>>n>>m;
        if(n==0 and m==0)break;
        ss.clear();
        ss.resize(n);
        string s;
        for(i=0;i<n;i++){
            cin>>s;
            ss[i] = s;
        }
        vector<pii> ans;
        for(k=0;k<26;k++){
            char alpha = k+'A';
            checked.clear();
            for(i=0;i<n;i++){
                for(j=0;j<m;j++){
                    //char ch=ss[i][j];
                    if(ss[i][j]==alpha and checked[{i,j}]==false){
                        int val=BFS({i,j},alpha);
                        ans.pb({val,k});
                        //dbg(ans);
                    }
                }
            }

        }
        sort(all(ans),comp);
        printf("Problem %d:\n",++t);
        for(i=0;i<ans.size();i++){
            char ch= ans[i].y+'A';
            cout<<ch<<' '<<ans[i].x<<endl;
        }
    }
    //free();   //if pointer array
    return 0;
}

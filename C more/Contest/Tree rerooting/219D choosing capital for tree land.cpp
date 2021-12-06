#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("showing %d\n",n)
#define p2(m,n) printf("showing %d %d\n",m,n)
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
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int dp[200005],mini=INF;
map<pii,bool> direction;
vector<int>v[200005],ans;
void build(int n,int pa=-1){
    for(int i=0;i<v[n].size();i++){
        int x=v[n][i];
        if(x==pa)continue;
        build(x,n);
        dp[n]+=dp[x]+direction[{x,n}];
    }
}
void update(int n,int x){
    dp[n]-=dp[x]+direction[{x,n}];
    dp[x]+=dp[n]+direction[{n,x}];
}
void reroot(int n,int pa){
    if(dp[n]==mini)ans.pb(n);
    else if(dp[n]<mini){
        mini=dp[n];
        ans.clear();
        ans.pb(n);
    }

    for(int i=0;i<v[n].size();i++){
        int x=v[n][i];
        if(x==pa)continue;
        update(n,x);
        reroot(x,n);
        update(x,n);
    }
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    for(i=1;i<n;i++){
        scanf("%d %d",&j,&k);
        direction[{j,k}]=true;
        v[j].pb(k);
        v[k].pb(j);
    }
    build(1);
    reroot(1,-1);
    sort(all(ans));

    printf("%d\n",mini);
    for(i=0;i<ans.size();i++)printf("%d ",ans[i]);
    //free();   //if pointer array
    return 0;
}

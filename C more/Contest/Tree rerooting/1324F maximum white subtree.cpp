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
const int maxed=200005;
int dp[maxed],value[maxed];
vector<int> v[maxed];

void build(int n,int pa){
    dp[n]=value[n];
    for(int i=0;i<v[n].size();i++){
        int x=v[n][i];
        if(x==pa)continue;
        build(x,n);
        if(dp[x]>0)dp[n]+=dp[x];
    }
}
void formate(int n,int x){
    if(dp[x]>0)dp[n]-=dp[x];
    if(dp[n]>0)dp[x]+=dp[n];
}
void reroot(int n,int pa){
    value[n]=dp[n];
    for(int i=0;i<v[n].size();i++){
        int x=v[n][i];
        if(x==pa)continue;

        formate(n,x);
        reroot(x,n);
        formate(x,n);
    }
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d",&val);
        if(!val)value[i+1]=-1;
        else value[i+1]=1;
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&j,&k);
        v[j].pb(k);
        v[k].pb(j);
    }
    build(1,-1);
    reroot(1,-1);
    for(i=0;i<n;i++)printf("%d ",value[i+1]);
    //free();   //if pointer array
    return 0;
}

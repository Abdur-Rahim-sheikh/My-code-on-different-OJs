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
ll dp[maxed],child[maxed];
int farthest,maxi;
map<int,int>level;
vector<int> v[maxed];
void findFarthest(int n,int pa){
    level[n]=level[pa]+1;
    if(level[n]>maxi)maxi=level[n],farthest=n;
    for(int u: v[n]){
        if(u==pa)continue;
        findFarthest(u,n);
    }
}
void playGame(int n,int pa,int &far){
    dp[n]=0LL;
    child[n]=1LL;
    level[n]=level[pa]+1;
    if(level[n]>maxi)maxi=level[n],far=n;
    for(int u: v[n]){
        if(u==pa)continue;
        playGame(u,n,far);
        child[n]+=child[u];
        dp[n]+=dp[u];
    }
    dp[n]+=child[n];
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    for(i=1;i<n;i++){
        scanf("%d %d",&j,&k);
        v[j].pb(k);
        v[k].pb(j);
    }
    findFarthest(1,-1);

    int secondFarthest;
    maxi=0;
    playGame(farthest,-1,secondFarthest);

    ll sum=dp[farthest];
    maxi=0;
    playGame(secondFarthest,-1,farthest);

    sum=max(sum,dp[secondFarthest]);
    printf("%lld\n",sum);
    //free();   //if pointer array
    return 0;
}

#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
//int row[4]={0,-1,0,1};
//int col[4]={-1,0,1,0};
using namespace std;
vector<int>net[10001];
int visit[10001],low[10001],parent[10001];
int tim,cnt,total;

void DFS(int n){
    visit[n]=low[n]=++tim;
    int len=net[n].size();
    bool arti=false;

    for(int i=0;i<len;i++){
        int val=net[n][i];
        if(val==parent[n])continue;

        if(visit[val])low[n]=min(visit[val],low[n]);
        else{
            if(parent[n]==(-1))cnt++;

            parent[val]=n;
            DFS(val);
            low[n]=min(low[n],low[val]);

            if(low[val]>=visit[n] && parent[n]!=(-1))arti=true;
        }
    }

    if(arti)total++;

}

void fresh(int n){
    total=cnt=tim=0;
    for(int i=0;i<=n;i++){
        parent[i]=visit[i]=0;
        net[i].clear();
    }

}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m;
        fresh(n);

        for(i=0;i<m;i++){
            scanf("%d %d",&k,&val);
            net[k].pb(val);
            net[val].pb(k);
        }
        parent[1]=-1;
        DFS(1);

        if(cnt>1)total++;


        printf("Case %d: %d\n",++t,total);
    }
    //free();   //if pointer array
    return 0;
}

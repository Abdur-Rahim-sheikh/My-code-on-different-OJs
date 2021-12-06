#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define pb push_back
#define pii pair<int,int>
using namespace std;
int dist[600];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dijkstra(int start,vector<pii>network[]);
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test,start;

    cin>>test;
    while(test--){
        vector<pair<int,int>> network[600];

        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d %d %d",&j,&k,&val);
            network[j].pb({k,val});
            network[k].pb({j,val});
        }

        dijkstra(1,network);
        printf("Case %d: ",++t);

        if(dist[n]==INF)printf("Impossible\n");
        else printf("%d\n",dist[n]);

    }


    //free();   //if pointer array
    return 0;
}
void dijkstra(int start,vector<pair<int,int> >network[]){
    bool checked[600]={false};
    fill(dist,dist+550,INF);
    dist[start]=0;

    q.push({0,start});
    while(!q.empty()){
        int a = q.top().second; q.pop();

        if(checked[a])continue;

        checked[a]=true;
        for(auto u: network[a]){
            int b= u.first,w = u.second;
            if(dist[a]+w <dist[b]){
                dist[b] = dist[a]+w;

                q.push({dist[b],b});
            }
        }
    }
}

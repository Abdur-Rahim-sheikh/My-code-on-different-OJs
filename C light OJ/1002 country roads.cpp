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

using namespace std;
int dist[600];

priority_queue<pair<int,int> > q;

void dijkstra(int start,vector<pair<int,int> >network[]);
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
        scanf("%d",&start);
        dijkstra(start,network);
        printf("Case %d:\n",++t);
        for(i=0;i<n;i++){
            if(dist[i]==INF)printf("Impossible\n");
            else printf("%d\n",dist[i]);
        }
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
            int p=max(dist[a],w);
            if(p<dist[b]){
                dist[b] =p;
                q.push({- dist[b],b});
            }
        }
    }
}

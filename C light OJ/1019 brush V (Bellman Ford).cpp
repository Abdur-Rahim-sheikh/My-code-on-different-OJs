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
#define mp make_pair
#define mt make_tuple
#define pb push_back
using namespace std;
int dist[600];
void Bellman_Ford(int start,int n,vector<tuple<int,int,int> > edges);
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;
    int a,b;
    cin>>test;
    while(test--){
        vector<tuple<int,int,int>> edges;
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&val);
            edges.pb(mt(a,b,val));
            edges.pb(mt(b,a,val));
        }
        Bellman_Ford(1,n,edges);
        if(dist[n]==INF)printf("Case %d: Impossible\n",++t);
        else printf("Case %d: %d\n",++t,dist[n]);
    }



    //free();   //if pointer array
    return 0;
}
void Bellman_Ford(int start,int n,vector<tuple<int,int,int> > edges){

    int a,b,val;

    fill(dist,dist+550,INF);
    dist[start]=0;
    for(int i=0;i<n;i++){
            bool dec=false;

        for(auto u : edges){
            tie(a,b,val) = u;
            if(dist[b]>dist[a]+val){
                dist[b]=dist[a]+val;
                dec=true;
            }
        }
        if(!dec)break;
    }
}

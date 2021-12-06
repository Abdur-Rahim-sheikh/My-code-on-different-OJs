#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define tii tuple<int,int,int>
using namespace std;
int dist[300];

void Bellman_Ford(int start,int n,vector<tii > &edges);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,a,b;
    cin>>test;
    while(test--){
        scanf("%d",&n);
        int arr[n+5];
        vector<tii>network;
        for(i=1;i<=n;i++)scanf("%d",&arr[i]);
        scanf("%d",&m);

        for(i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            network.pb(make_tuple(a,b,arr[b]));
        }

        scanf("%d",&k);
        printf("Case %d:\n",++t);
        for(i=0;i<k;i++){
            scanf("%d",&val);
            if(dist[val]==INF || dist[val]==1)printf("?\n");
            printf("%d\n",dist[val]);
        }
    }



    //free();   //if pointer array
    return 0;
}

void Bellman_Ford(int start,int n,vector<tii > &edges){

    int a,b,val;

    fill(dist,dist+250,INF);
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

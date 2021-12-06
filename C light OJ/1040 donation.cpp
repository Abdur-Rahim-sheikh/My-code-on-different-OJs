#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
int parent[50+10];

struct edge{
    int a,b,w;
    bool operator<(const edge &x)const
    {
        return w<x.w;
    }

};
int find_parent(int n);
int mst_min(int n,vector<edge> & network);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d",&n);
        vector<edge>network;
        int sum=0;
        for(i=0;i<n;i++)  for(j=0;j<n;j++){
            scanf("%d",&val);
            if(val!=0){
                edge tem;
                tem.a=i;
                tem.b=j;
                tem.w=val;
                network.pb(tem);
                sum+=val;
            }
        }
        int needed=mst_min(n,network);
        int  with=find_parent(0);
        for(i=0;i<n;i++){
            if(with!=find_parent(i))break;
        }
        if(i==n)printf("Case %d: %d\n",++t,sum-needed);
        else printf("Case %d: -1\n",++t);
    }



    //free();   //if pointer array
    return 0;
}


int find_parent(int n){

    if(parent[n]==n)return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}
int mst_min(int n,vector<edge> & network){
    sort(network.begin(),network.end());

    int len = network.size();
    int i,l,r,sum=0;

    for(i=0;i<n+5;i++)parent[i]=i;
    for(i=0;i<len;i++){

        l = find_parent(network[i].a);
        r = find_parent(network[i].b);
        if(l!=r){

            parent[l]=r;
            sum+=network[i].w;
        }
    }
    return sum;
}

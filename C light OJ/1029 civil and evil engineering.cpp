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
#define pb push_back
#define M 120
using namespace std;

int parent[200];
struct edge{
    int a,b,w;
};
bool incre(edge a,edge b){return a.w<b.w;}
bool decre(edge a,edge b){return a.w>b.w;}
int find_parent(int n);
ll mst_min(int n,vector<edge> &network);
ll mst_max(int n,vector<edge> &network);
int main()
{

    int i,j,k,m,n,val,t=0,test;
    ll sum;
    int a,b;
    cin>>test;
    while(test--){
        vector<edge>network;
        sum =0;
        scanf("%d",&n);
        while(true){
            scanf("%d %d %d",&a,&b,&val);
            if(a==b && b==val && val==0)break;

            network.pb({a,b,val});
        }

        sum = (ll)mst_min(n,network);

        sum+= (ll)mst_max(n,network);

        if(sum%2 ==0 )printf("Case %d: %lld\n",++t,sum/2);
        else printf("Case %d: %lld/2\n",++t,sum);

    }



    //free();   //if pointer array
    return 0;
}
int find_parent(int n){

    if(parent[n]==n)return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}
ll mst_min(int n,vector<edge> & network){
    sort(network.begin(),network.end(),incre);

    int len = network.size();
    int i,l,r;
    ll sum=0;

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

ll mst_max(int n,vector<edge> & network){
    sort(network.begin(),network.end(),decre);
    int len = network.size();
    int i,l,r;
    ll sum=0;

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

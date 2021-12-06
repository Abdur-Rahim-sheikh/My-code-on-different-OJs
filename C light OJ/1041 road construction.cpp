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
using namespace std;
int parent[50+10];

struct edge{
    int a,b,w;
};

bool incre(edge a,edge b){return a.w<b.w;}
int find_parent(int n);
int mst_min(vector<edge> & network);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;


    cin>>test;
    while(test--){

        scanf("%d",&m);
        map<string,int> hash_t;

        vector<edge>network;
        string a,b;
        for(i=1;i<=m+5;i++)parent[i]=i;
        for(i=0,cnt=0;i<m;i++){
            cin>>a>>b>>val;

            if(hash_t[a] == 0)cnt++ , hash_t[a] = cnt;
            if(hash_t[b] == 0)cnt++ , hash_t[b] = cnt;

            if(val ==0){
                int p = find_parent(hash_t[a]);
                int q = find_parent(hash_t[b]);
                if(p != q)parent[p]=q;
            }

            else  network.pb({hash_t[a],hash_t[b],val});

        }

        int save = mst_min(network);
        set<int> p;
        for(i=1;i<=cnt;i++){
             p.insert(find_parent(i));
        }

        if(p.size()>1)printf("Case %d: Impossible\n",++t);
        else printf("Case %d: %d\n",++t,save);

    }



    //free();   //if pointer array
    return 0;
}



int find_parent(int n){

    if(parent[n]==n)return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}
int mst_min(vector<edge> & network){
    sort(network.begin(),network.end(),incre);

    int len = network.size();
    int i,l,r,sum=0;


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

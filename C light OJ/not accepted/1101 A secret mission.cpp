#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
int pa[50004];
int level[50004];
int parent[50004];
int sum[50004];
int arr[20][50004];
struct edge{
    int a,b,w;
    bool operator<(const edge &x)const
    {
        return w<x.w;
    }

};
int find_parent(int n){

    if(pa[n]==n)return n;
    pa[n] = find_parent(pa[n]);
    return pa[n];
}
int DFS(int lv,int pa,int n,int val,vector<pii> net[]){
    level[n]=lv;
    parent[n]=pa;
    sum[n]=val;
    for(int i=0;i<net[n].size();i++){
        int m=net[n][i].x;
        if(m==pa)continue;
        DFS(lv+1,n,m,sum[n]+net[n][i].y,net);
    }

}
void mst_min(int n,vector<edge> & network){
    sort(network.begin(),network.end());

    int len = network.size();
    int i,l,r;
    vector<pii> net[n+5];
    for(i=0;i<n+5;i++)pa[i]=i;
    for(i=0;i<len;i++){
        int a=network[i].a;
        int b=network[i].b;
        int w=network[i].w;
        l = find_parent(a);
        r = find_parent(b);
        if(l!=r){
            pa[l]=r;
            net[a].pb({b,w});
            net[b].pb({a,w});
            cout<<a<<' '<<b<<' '<<w<<endl;
        }
    }
    DFS(0,-1,l,0,net);
}


void sparse(int n){
    int i,j;
    memset(arr,-1,sizeof arr);
    for(i=0;i<n;i++)arr[0][i]=parent[i];
    for(i=1;(i<<i)<=n;i++){
        for(j=0;j<n;j++){
            if(arr[i-1][j]!=(-1))arr[i][j]=arr[i-1][arr[i-1][j]];
        }
    }
}
int LCA(int m,int k){
    int total=sum[m]+sum[k];
    if(level[m]<level[k])swap(m,k);
    for(int i=log2(level[m]);i>=0;i--){
        if(level[m]-(1<<i)>=level[k])m=arr[i][m];
    }
    for(int i=log2(level[m]);i>=0;i--){
        if(arr[i][m]!=(-1) and arr[i][m]!=arr[i][k]){
            m=arr[i][m];
            k=arr[i][k];
        }
    }
    return total-2*sum[k];
}
int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m;
        vector<edge> network;
        for(i=0;i<m;i++){
            scanf("%d %d %d",&j,&k,&val);
            network.pb({j,k,val});
        }
        mst_min(n,network);
        sparse(n);
        cin>>k;
        int a,b;
        printf("Case %d:\n",++t);
        for(i=0;i<k;i++){
            cin>>a>>b;
            printf("%d\n",LCA(a,b));
        }
    }
    //free();   //if pointer array
    return 0;
}

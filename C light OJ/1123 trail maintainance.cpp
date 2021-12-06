#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
int parent[205];
int length[205];
struct edge{
    int a,b,w;
    bool operator<(const edge &x)const
    {
        return w<x.w;
    }

};
int find_parent(int n);
vector<edge>network,temp;


int mst_min();

void refresh(){for(int i=0;i<202;i++)parent[i]=i,length[i]=1;}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,len;

    //freopen("000input.txt","r",stdin);

    cin>>test;

    while(test--){
        scanf("%d %d",&n,&m);
        network.clear();

        bool can_span=false;
        printf("Case %d:\n",++t);
        for(i=0;i<m;i++){
            scanf("%d %d %d",&j,&k,&val);
            refresh();
            edge tem;
            tem.a=j;
            tem.b=k;
            tem.w=val;
            network.pb(tem);

            if(!can_span){
                for(j=0;j<network.size();j++){
                    int l=find_parent(network[j].a);
                    int r=find_parent(network[j].b);
                    if(l!=r){
                        parent[l]=r;
                        length[r]+=length[l];
                    }
                }
                if(length[find_parent(1)]==n)can_span=true,refresh();
                else printf("-1\n");
            }
            if(can_span){
                sort(network.begin(),network.end());
                int sum=mst_min();
                printf("%d\n",sum);
                network.clear();
                network.assign(temp.begin(),temp.end());
            }
        }

    }



    //free();   //if pointer array
    return 0;
}



int find_parent(int n){

    if(parent[n]==n)return n;
    parent[n] = find_parent(parent[n]);
    return parent[n];
}
int mst_min(){

    int len = network.size();
    int i,l,r,sum=0;
    temp.clear();
    for(i=0;i<len;i++){

        l = find_parent(network[i].a);
        r = find_parent(network[i].b);
        if(l!=r){
            temp.pb(network[i]);
            if(length[l]>length[r])swap(l,r);
            parent[l]=r;
            length[r]+=length[l];
            sum+=network[i].w;
        }
    }
    return sum;
}

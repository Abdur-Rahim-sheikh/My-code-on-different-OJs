#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

map<int,vector<int> >network;
queue<int> que;
map<int,bool> checked;
map<int,int> level;
map<int,bool>camebefore;
int BFS(int node,int ttl);
int main()
{

    int a,b,i,j,k,m,n,val,t=0,test,node,ttl,total;
    freopen("000input.txt","r",stdin);
    while(cin>>n && n!=0){
            total=0;
            map<int,int>address;
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
           // cout<<address[a]<< ' '<<address[b]<<endl;

            if(address[a]==0)address[a]=++total;
            if(address[b]==0)address[b]=++total;

           if(a==b && camebefore[a]==true)continue;

            network[a].push_back(b);
            if(a!=b) network[b].push_back(a);
            else camebefore[a]=true;


        }

        while(1){
            scanf("%d %d",&node,&ttl);
            if(node==0 && ttl==0)break;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++t,total-BFS(node,ttl),node,ttl);

           checked.clear();
           level.clear();
        }
        network.clear();
    }
    //free();   //if pointer array
    return 0;
}

int BFS(int node,int ttl){
   // cout<<network[node].size()<<' '<<node<<endl;
    if(network[node].size()==0) return 0;

    int cnt=0;

    checked[node]=true;
    level[node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int val=network[n][i];
                if(val==n)cnt++;
            if(checked[val]==false){
                checked[val]=true;
                level[val]=level[n]+1;
                que.push(val);



                ///printf("%d\n",val);
                if(level[val]>ttl)///those are out of range
                {
                    while(!que.empty())que.pop();

                    return cnt+1;
                }
                 cnt++;

            }
        }
    }
    return cnt+1;

}




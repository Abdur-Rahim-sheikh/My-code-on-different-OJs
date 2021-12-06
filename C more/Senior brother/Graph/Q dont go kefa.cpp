#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

vector<int>path[100000];
bool cats[100000];
int level[100000];
bool checked[100000];
queue<int>que;
int BFS(int node,int m);
int main()
{

    int i,j,k,m,n,val,t=0,test,a,b;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&val);
        if(val==1)cats[i]=true;

    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        path[a].push_back(b);
        path[b].push_back(a);
    }
    printf("%d\n",BFS(1,m));
    //free();   //if pointer array
    return 0;
}

int BFS(int node,int m){
    int store=0;
    checked[node]=true;
    if(cats[node]==true)level[node]=1;
    else level[node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=path[n].size();
        for(int i=0;i<len;i++){
            int val=path[n][i];



            if(checked[val]==false){
                checked[val]=true;
                if(cats[val]==true)
                    level[val]=level[n]+1;
                else level[val]=0;

                if(level[val]>m) continue;

                que.push(val);
                //printf("%d %d %d %d\n",val,path[val].size(),level[val],store);
                if(level[val]<=m && path[val].size()==1) store++;

            }
        }
    }
    return store;  ///store-super_counted.

}

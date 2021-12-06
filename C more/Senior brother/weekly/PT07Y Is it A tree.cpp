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
using namespace std;
bool checked[10004];
int level [10004];
queue<int>que;

bool BFS(int node,vector<int>network[]);
int main()
{

    int i,j,k,m,n,val,t=0,test;

    cin>>n>>m;
    vector<int> network[n+5];

    for(i=0;i<m;i++){
        scanf("%d %d",&k,&val);

        network[k].push_back(val);
        network[val].push_back(k);
    }

    for(i=1;i<=n;i++){
        if(checked[i]==false && network[i].size()!=0){
                bool k;
                k=BFS(i,network);
            if( k==false) { printf("NO\n"); return 0;}
        }
    }
    printf("YES\n");
    //free();   //if pointer array
    return 0;
}


bool BFS(int node,vector<int>network[]){
    checked[node]=true;

    level[node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int val=network[n][i];
            if(checked[val]==false){
                checked[val]=true;
                level[val]=level[n]+1;
                que.push(val);

            }
            else if((level[val]+1)!=level[n])return false;
        }
    }
   return true;

}

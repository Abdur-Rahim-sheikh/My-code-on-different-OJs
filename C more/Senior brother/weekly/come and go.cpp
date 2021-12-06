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
map<int,bool> checked;
//int level[1000];
queue<int>que;
void BFS(int node,vector<int>network[]);
int main()
{

    int i,j,k,m,n,val,t=0,test;

    while(scanf("%d %d",&n,&m)){
            if(n==0 && m==0 )break;
        vector<int>network[3000];
        for(i=0;i<m;i++){
            scanf("%d %d %d",&j,&k,&t);
            if(t--)network[j].push_back(k);
            if(t)network[k].push_back(j);
        }
        for(i=1;i<=n;i++){
            BFS(i,network);
            for(j=1;j<=n;j++) if(checked[j]==false)break;

             checked.clear();

            if(j<=n)break;


        }

        if(i>n)printf("1\n");
        else printf("0\n");



    }
    //free();   //if pointer array
    return 0;
}




void BFS(int node,vector<int>network[]){
    checked[node]=true;

    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int val=network[n][i];
            if(checked[val]==false){
                checked[val]=true;

                que.push(val);

            }
        }
    }


}

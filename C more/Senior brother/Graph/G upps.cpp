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
bool checked[1000];
int level[1000];
queue<int>que;


int BFS(int node,int dest,vector<int> network[]);
int main()
{

    int i,j,k,m,n,val,t=0,test;

    while(1){
            vector<int>network[200];
        for(i=1;i<20;i++){
            if(scanf("%d",&n)==EOF)return 0;
            for(j=0;j<n;j++){
                scanf("%d",&val);
                network[i].push_back(val);
                network[val].push_back(i);


            }
        }
        scanf("%d",&test);
        printf("Test Set #%d\n",++t);
        while(test--){
                int start,ends;
            scanf("%d %d",&start,&ends);
            printf("%2d to %2d:%2d\n",start,ends,BFS(start,ends,network));

             for(i=1;i<22;i++){
                  checked[i]=false;level[i]=0;
             }
        }
        printf("\n");
    }
    //free();   //if pointer array
    return 0;
}


int BFS(int node,int dest,vector<int> network[]){
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
                if(val==dest){
                    while(!que.empty())que.pop();

                    return level[val];
                }
                que.push(val);

            }
        }
    }


}


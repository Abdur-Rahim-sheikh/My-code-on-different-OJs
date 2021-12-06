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
bool checked[100005];
int level[100005];


int BFS(int node,vector<int>network[]);
int main()
{

    int i,j,k,m,n,val,t=0,test,maximum;
    cin>>test;
    while(test--){

        vector<int> network[100006];
        map<int,int>squize;
        int total=0,maximum=0;
        //global
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d %d",&k,&m);
            if(squize[k]==0){
                squize[k]=++total;

            }
            if(squize[m]==0){
                squize[m]=++total;

            }
            network[squize[k]].push_back(squize[m]);
            network[squize[m]].push_back(squize[k]);

            checked[squize[k]]=false;checked[squize[m]]=false;
        }
        for(i=1;i<=total;i++){
            if(checked[i]==false){
                maximum += BFS(i,network);

            }
        }
        printf("Case %d: %d\n",++t,maximum);

    }
    //free();   //if pointer array
    return 0;
}

int BFS(int node,vector<int>network[]){

    int twoside[2]={0};
    queue<int>que;
    checked[node]=true;
    level[node]=0;
    twoside[0]++;

    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=network[n].size();

        for(int i=0;i<len;i++){
            int val=network[n][i];
                if(checked[val]==false){
                     checked[val]=true;
                    level[val]=(level[n]==0?1:0);
                    twoside[level[val]]++;
                    que.push(val);
                }
        }
    }
    return max(twoside[0],twoside[1]);

}


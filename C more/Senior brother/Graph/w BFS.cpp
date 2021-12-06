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
bool checked[300000];
int level[300000];
queue<int>que;
vector<int> network[300000];


void BFS(int node);
int main()
{

    int i,j,k,m,n,val,t=0,test;
    cin>>n;
    for(i=1;i<n;i++){
        scanf("%d %d",&m,&k);
        network[m].push_back(k);
        network[k].push_back(m);
    }

    BFS(1);

    int sign=0,previous=0;

    for(i=0;i<n;i++){
        scanf("%d",&val);
       // cout<<level[val]<<' '<<val<<endl;
        if(level[val]==previous+1)previous++;
        else if(level[val]<previous  || level[val]>previous+1)sign=1;
    }
    if(sign) printf("NO\n");
    else printf("YES\n");
    //free();   //if pointer array
    return 0;
}

void BFS(int node){
    checked[node]=true;
    level[node]=1;
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
        }
    }


}


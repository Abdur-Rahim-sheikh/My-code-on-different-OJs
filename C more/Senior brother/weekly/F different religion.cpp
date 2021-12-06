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
map<int,bool> checked;
queue<int>que;

void BFS(int node ,vector<int> network[]);
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;
    while(scanf("%d %d",&n,&m) && n!=0 && m!=0){
        vector<int> network[n+5];

        for(i=0;i<m;i++){
            scanf("%d %d",&j,&k);
            network[j].push_back(k);
            network[k].push_back(j);
        }
        for(i=1;i<=n;i++){
            if(checked[i]==false) BFS(i,network),cnt++;
        }
        printf("Case %d: %d\n",++t,cnt);

        cnt=0;checked.clear();
    }

    //free();   //if pointer array
    return 0;
}

void BFS(int node ,vector<int> network[]){
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

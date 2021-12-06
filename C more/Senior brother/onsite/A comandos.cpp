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
int   level[2000],leaf_level[2000];
queue<int>que;
queue<int> leaf;
int BFS(int node,int stop,vector<int>network[]);
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test,a,b,start,ending;

    cin>>test;
    while(test--){
        scanf("%d %d",&n,&m);

        int previous=0;
        vector<int> network[n+5];
        for(i=0;i<m;i++){
            scanf("%d %d",&a,&b);

            network[a].push_back(b);
            network[b].push_back(a);

        }
        scanf("%d %d",&start,&ending);

        BFS(start,-1,network);
        //for(i=0;i<=n;i++) checked[i]=level[i]=0;
        checked.clear();
        while(!leaf.empty()){
            int val=leaf.front();
            leaf.pop();

            int a=BFS(val,ending,network);

            checked.clear();
            if(leaf_level[val]+a>previous)previous=leaf_level[val]+a;
        }

        printf("Case %d: %d\n",++t,previous);
    }
    //free();   //if pointer array
    return 0;
}


int BFS(int node,int stop,vector<int>network[]){
    checked[node]=true;
    level[node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front(),t=0;
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int val=network[n][i];
            if(checked[val]==false){
                checked[val]=true;
                level[val]=level[n]+1;

                if(val==stop){
                    while(!que.empty())que.pop();

                    return level[val];
                }

                que.push(val);
                t++;
            }
        }
        if(t==0 && stop==(-1)) leaf.push(n),leaf_level[n]=level[n];
    }
    return 0;

}

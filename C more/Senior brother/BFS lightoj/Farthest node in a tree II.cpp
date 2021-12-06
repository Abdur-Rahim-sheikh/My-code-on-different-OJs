#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
bool checked[40000];
int level[2][40000];
queue<int>que;
int BFS(int node,int ith,vector<pii> network[]);
void refresh();
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    cin>>test;
    while(test--){
        scanf("%d",&n);
        vector<pii> network[n+5];
        for(i=0;i<n-1;i++){
            scanf("%d %d %d",&k,&m,&val);
            network[k].pb({m,val});
            network[m].pb({k,val});
        }

        ///finding one of farthest
        int farthest = BFS(0,0,network);
       // cout<<farthest<<endl;

        /// marking  0'th level  from the first farthest
        farthest = BFS(farthest,0,network);

        ///above returned farthest is the location of opposite farthest
        /// so marking 1'th level from the opposite farthest
        farthest = BFS(farthest,1,network);
        printf("Case %d:\n",++t);
        for(i=0;i<n;i++){
            printf("%d\n",max(level[0][i],level[1][i]));
        }
    }



    //free();   //if pointer array
    return 0;
}
void refresh(){
    for(int i=0;i<31000;i++)checked[i]=false;
}


int BFS(int node,int ith,vector<pii> network[]){
    refresh();
    checked[node]=true;
    int maxi=0,ind;
    level[ith][node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            pii val=network[n][i];
            if(checked[val.first]==false){
                checked[val.first]=true;
                level[ith][val.first]=level[ith][n]+val.second;
                if(level[ith][val.first]>maxi){
                    maxi=level[ith][val.first];
                    ind = val.first;
                }
                que.push(val.first);

            }
        }
    }
   return ind;

}

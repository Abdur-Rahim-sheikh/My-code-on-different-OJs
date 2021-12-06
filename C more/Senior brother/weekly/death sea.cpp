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

bool checked[30];
int level[30];
queue<int>que;
vector<int> network[30];
int BFS(int node,int top);
int main()
{

    int i,j,k,m,n,val,t=0,test,arr[40],sum=0;

    cin>>test;
    while(test--){
        scanf("%d",&n);
        int prev=n,sign=0;
        for(i=0;i<n;i++) scanf("%d",&arr[i]),level[i]=0,checked[i]=false;

        for(i=1;i<n-1;i++){
            if(i+arr[i]>=0 && (i)+arr[i]<=n) network[i].push_back(i+arr[i]);
            network[i].push_back(i-1);
            network[i].push_back(i+1);
        network[0].push_back(1);
        if(arr[0]>=0 && arr[0]<=n)network[0].push_back(arr[0]);

        if(n>1){
                network[n-1].push_back(n-2);
                    if((n-1)+arr[n-1]>=0 && (n-1)+arr[n-1]<=n)network[n-1].push_back(n-1+arr[n-1]);
        }

        for(i=0;i<n;i++){

            k=BFS(i,n);
            sum=i+k;
            if(sum<prev && k>(-1))prev=sum;
        }
        printf("%d\n",prev);
    }
    //free();   //if pointer array
    return 0;
}



int BFS(int node,int top){
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
                if(val==top){
                    while(!que.empty())que.pop();
                    return level[val];
                }

            }
        }
    }
   return -1;

}

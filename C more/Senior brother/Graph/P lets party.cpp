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
vector<int>immediate_junior[2010];
queue<int>que;
bool checked[2010];
int minimumGroup[2010];

int previous=1;

void BFS(int start);
int main()
{

    int i,j,k,m,n,val,t=0,test,superior[2010];

    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        if(k==(-1)){
            superior[t++]=i;
        }
        else immediate_junior[k].push_back(i);
    }

    for(i=0;i<t;i++){

         BFS(superior[i]);
         for(j=0;j<=n;j++) checked[j]=0,minimumGroup[j]=0;
    }

    printf("%d\n",previous);
    //free();   //if pointer array
    return 0;
}
void BFS(int start){
    checked[start]=true;
    minimumGroup[start]=1;
    que.push(start);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=immediate_junior[n].size();
        for(int i=0;i<len;i++){
            int val=immediate_junior[n][i];
            if(checked[val]==false){
                checked[val]=true;
                que.push(val);
                minimumGroup[val]=minimumGroup[n]+1;

               /// printf("%d %d\n",minimumGroup[val],val);

                if(minimumGroup[val]>previous)previous=minimumGroup[val];
            }
        }
    }

}

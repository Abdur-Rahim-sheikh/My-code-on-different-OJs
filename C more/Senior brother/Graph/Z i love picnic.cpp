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
map<int,int> number_of_visit;
queue<int>que;

void BFS(int node,vector<int> network[]);
int main()
{

    int i,j,k,m,n,val,t=0,test,person[2000],a,b;

    cin>>test;
    while(test--){
        scanf("%d %d %d",&k,&n,&m);
        vector<int>network[n+10];
        for(i=0;i<k;i++) scanf("%d",&person[i]);

        for(i=0;i<m;i++) {
            scanf("%d %d",&a,&b);
            network[a].push_back(b);

        }
         for(j=0;j<k;j++){
             BFS(person[j],network);
            checked.clear();
         }
        int cnt=0;
        for(i=1;i<=n;i++){

            if(number_of_visit[i]==k)cnt++;
        }

        printf("Case %d: %d\n",++t,cnt);

        number_of_visit.clear();
    }
    //free();   //if pointer array
    return 0;
}


void BFS(int node,vector<int> network[]){
    checked[node]=true;
    number_of_visit[node]++;
    que.push(node);
    while(!que.empty()){

        int n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int val=network[n][i];
            if(checked[val]==false){
                checked[val]=true;
                number_of_visit[val]++;
                que.push(val);

            }
        }
    }


}

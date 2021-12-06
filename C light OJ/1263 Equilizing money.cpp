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

bool checked[1000];

queue<int>que;

pii BFS(int node,vector<int> network[],int arr[]);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;
    int arr[2000];
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&m);
        vector<int> network[m+2];
        for(i=1;i<=n;i++)scanf("%d",&arr[i]),checked[i]=false;

        for(i=0;i<m;i++){
            scanf("%d %d",&j,&k);
            network[j].pb(k);
            network[k].pb(j);
        }
        bool possible =false;
        pii sum=BFS(1,network,arr);
        //cout<<sum.first<<' '<<sum.second<<endl;
        if(sum.first%sum.second==0){

            possible = true;
            int money = sum.first/sum.second;
            pii demo;
            for(i=1;i<=n;i++){
                if(checked[i]==false){
                    demo=BFS(i,network,arr);
                    if(demo.first%demo.second!=0 || (demo.first/demo.second)!=money)possible=false;
                }

            }

        }
        if(possible)printf("Case %d: Yes\n",++t);
        else printf("Case %d: No\n",++t);
    }


    //free();   //if pointer array
    return 0;
}

pii BFS(int node,vector<int> network[],int arr[]){
    checked[node]=true;

    int cnt=1,sum=0;
    sum=arr[node];
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
                sum+=arr[val];
                cnt++;
            }
        }
    }
   return mp(sum,cnt);

}

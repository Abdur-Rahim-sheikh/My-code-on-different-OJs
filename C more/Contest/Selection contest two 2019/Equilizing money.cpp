#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;
bool checked[1005];
int money[1005],sum;
queue<int>que;
bool BFS(int node,vector<int> network[]);
int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m;
        vector<int>network[n+4];
        for(i=1;i<=n;i++){
            scanf("%d",&money[i]);
            checked[i]=false;
        }

        for(i=0;i<m;i++){
            scanf("%d %d",&j,&k);
            network[j].pb(k);
            network[k].pb(j);
        }
        bool possible=false;
        int same;
        for(i=1;i<=n;i++){

            if(!checked[i]){
                possible=BFS(i,network);
                if(i==1)same=sum;
            }
            if(!possible || sum!=same)break;
        }
        if(i<=n)printf("Case %d: No\n",++t);
        else printf("Case %d: Yes\n",++t);
    }
    //free();   //if pointer array
    return 0;
}



bool BFS(int node,vector<int> network[]){
    checked[node]=true;
    int total=1;
    sum=money[node];
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int val=network[n][i];
            if(checked[val]==false){
                checked[val]=true;
                total++;
                sum+=money[val];
                que.push(val);

            }
        }
    }
   if(sum%total==0)return true,sum=sum/total;
   else return false;

}

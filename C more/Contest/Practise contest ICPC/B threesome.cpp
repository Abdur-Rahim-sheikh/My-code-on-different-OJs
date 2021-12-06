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
int sum;
int arr[400];
int parent[400];
bool checked[400];
int level[400];
vector<pii>network[400];
queue<int>que;
void BFS(int n);
void refresh(){
    for(int i=0;i<301;i++)arr[i]=parent[i]=checked[i]=level[i]=0;
}
int main(){

    int i,j,k,m,n,val,t=0,cnt,test,a,b;

    freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        sum=0;
        for(i=0;i<n+5;i++)network[i].clear();
        k=(n*(n-1))/2;
        for(i=0;i<k;i++){
            scanf("%d %d %d",&a,&b,&val);
            network[a].pb({b,val});
            network[b].pb({a,val});
        }
        for(i=1,sum=0;i<=n;i++){
            refresh();
            BFS(i);
        }
        printf("%d\n",sum);
    }
    //free();   //if pointer array
    return 0;
}

void BFS(int node){
    checked[node]=1;
    level[node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front();

        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int val=network[n][i].first;
            int p=network[n][i].second;


            if(checked[val]==false){
                level[val]=level[n]+1;
                arr[val]=arr[n]+p;
                parent[val]=n;
                checked[val]=true;
                if(level[val]<=2)que.push(val);

            }
            else if(level[n]==2){

                int k=parent[parent[n]];
                if(k==val && arr[n]+p-arr[val]>sum)sum=arr[n]+p-arr[val];
            }
        }
    }
}



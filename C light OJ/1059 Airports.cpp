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
int price;
bool checked[10004];
struct compare{
    bool operator()(pii const& a,pii const &b){return a.second>b.second;}
};
int prims_mst(int start,vector<pii>network[]){
    int sum=0;
    priority_queue<pii,vector<pii>,compare> q;
    q.push({start,0});
    while(!q.empty()){
        int n = q.top().first;
        int p = q.top().second;
        q.pop();

        if(checked[n]==true)continue;

        sum+=p;
        checked[n]=true;
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int k=network[n][i].first;
            int p=network[n][i].second;

            if(checked[k]==false)q.push(network[n][i]);

        }
    }
    return sum;
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,cost;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d %d %d",&n,&m,&price);
        vector<pii> network[n+5];
        for(i=1;i<=n;i++)checked[i]=false;
        for(i=0;i<m;i++){
            scanf("%d %d %d",&j,&k,&cost);
            if(price>cost){
                network[j].pb({k,cost});
                network[k].pb({j,cost});
            }

        }
        int count =0,sum=0;
        for(i=1;i<=n;i++){
            if(checked[i]==false){
                count++;
                sum+=prims_mst(i,network);
            }
        }
        printf("Case %d: %d %d\n",++t,sum+(count*price),count);
    }
    //free();   //if pointer array
    return 0;
}

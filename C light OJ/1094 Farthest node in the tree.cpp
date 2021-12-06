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
#define pii pair<long long,long long>
using namespace std;
ll first,pos;
map<int,bool> checked;

ll level[40000];

void dfs(ll start,map<ll,vector<pii> > &network){
    if(checked[start])return;
    checked[start]=true;
    for(auto u: network[start]){
        if(checked[u.first])continue;
        level[u.first]=level[start]+u.second;
        if(level[u.first]>first){
            first=level[u.first];
            pos=u.first;
        }
        dfs(u.first,network);
    }
    return;
}
int main()
{

    ll i,j,k,m,n,val,t=0,cnt,test,prev;
    cin>>test;
    while(test--){
        scanf("%lld",&n);
        map<ll,vector<pii> > network;

        for(i=1;i<n;i++){
            scanf("%lld %lld %lld",&j,&k,&m);
            network[j].pb({k,m});
            network[k].pb({j,m});
        }

        first=0;
        level[0]=0;
        dfs(0,network);
        checked.clear();

		first=0;
		level[pos]=0;
        dfs(pos,network);
        checked.clear();

        printf("Case %lld: %lld\n",++t,level[pos]);
    }



    //free();   //if pointer array
    return 0;
}

#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
vector<int> net[10005];
stack<int> st;
bool visit[10005];
void topsort(int n,bool keep){
    visit[n]=true;
    for(int i=0;i<net[n].size();i++){
        if(!visit[net[n][i]])topsort(net[n][i],keep);
    }

    if(keep)st.push(n);
    return;
}
void refresh(int n,bool all){
    for(int i=0;i<=n;i++){if(all)net[i].clear();visit[i]=false;}
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;
    int a,b;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&m);
        refresh(n,true);

        for(i=0; i<m ;i++){
            scanf("%d %d",&a,&b);
            net[a].pb(b);
        }
        stack<int>tem;
        swap(tem,st);
        for(i=1;i<=n;i++)if(!visit[i])topsort(i,true);

        refresh(n,false);
        cnt=0;
        while(!st.empty()){
            if(!visit[st.top()])topsort(st.top(),false),cnt++;
            st.pop();
        }
        printf("Case %d: %d\n",++t,cnt);
    }



    //free();   //if pointer array
    return 0;
}

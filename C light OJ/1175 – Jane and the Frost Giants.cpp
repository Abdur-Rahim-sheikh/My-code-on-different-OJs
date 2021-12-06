#include<bits/stdc++.h>
#define INF 107374182
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("showing %d\n",n)
#define p2(m,n) printf("showing %d %d\n",m,n)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
int row[8]={0,-1,0,1,1,-1,-1,1};
int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
string s[202];
int m,n;
int level[202][202];
bool valid(int i,int j){
    if(i>=0 and i<m and j>=0 and j<n and s[i][j]!='#')return true;
    else return false;
}
bool edge(pii tem){
    return (!(tem.x and tem.y) or tem.x==m-1 or tem.y==n-1);
}
int BFS(int i,int j){
    level[i][j]=0;
    queue<pii> q;
    q.push({i,j});
    bool exit=false;
    int len=-1;
    while(!q.empty()){
        pii tem=q.front();q.pop();
        if(edge(tem) and !exit)exit=true,len=level[tem.x][tem.y];
        for(int i=0;i<4;i++){
            int a=tem.first+row[i];
            int b=tem.second+col[i];
            if(valid(a,b) and level[a][b]>level[tem.x][tem.y]+1){
                q.push({a,b});
                level[a][b]=level[tem.x][tem.y]+1;
            }
        }
    }
    return len+1;
}
int main(){
    int i,j,k,val,t=0,cnt,test;
    ///freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>m>>n;
        for(i=0;i<m;i++)cin>>s[i];
        pii tem;
        for(i=0;i<m;i++)fill(level[i],level[i]+n,INF);

        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(s[i][j]=='F')BFS(i,j);
                if(s[i][j]=='J')tem=mp(i,j);
            }
        }

        int ans=BFS(tem.x,tem.y);
        if(ans)printf("Case %d: %d\n",++t,ans);
        else printf("Case %d: IMPOSSIBLE\n",++t);
    }
    //free();   //if pointer array
    return 0;
}

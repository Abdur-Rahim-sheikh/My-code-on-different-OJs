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

int row[]={0,-1,0,1};
int col[]={-1,0,1,0};
string arr[300];
bool checked[300][300];
int level[300][300];
queue<pii>que;
void make_relation(pii position,pii bounds,map<pii,vector<pii>>& network);
int escaper_BFS(pii node,int m,int n,map<pii,vector<pii> >&network);
void fired_BFS(pii node,map<pii,vector<pii> >&network);
void refresh();
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;

    cin>>test;
    while(test--){
        scanf("%d %d",&m,&n);
        map<pii,vector<pii> > network;
        for(i=0;i<m;i++)cin>>arr[i];
        queue<pii> fire;
        pii start;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++){
                make_relation({i,j},{m,n},network);
                if(arr[i][j]=='J')start = {i,j};
                if(arr[i][j]=='F')fire.push({i,j});
                checked[i][j]=false;
                level[i][j]=INF;
            }

        while(!fire.empty()){
            fired_BFS(fire.front(),network);
            fire.pop();
        }
        int lvl = escaper_BFS(start,m,n,network);
        if(lvl==(-1))printf("Case %d: Impossible\n",++t);
        else printf("Case %d: %d\n",++t,lvl+1);

    }



    //free();   //if pointer array
    return 0;
}

int escaper_BFS(pii node,int m,int k,map<pii,vector<pii> >&network){
    refresh();
    checked[node.first][node.second]=true;
    level[node.first][node.second]=0;
    que.push(node);
    while(!que.empty()){
        pii n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            pii val=network[n][i];
            if(checked[val.first][val.second]==false && level[val.first][val.second]>level[n.first][n.second]+1){
                checked[val.first][val.second]=true;

                level[val.first][val.second]=level[n.first][n.second]+1;
                if(val.first==0 || (val.first == m-1) || val.second==0 || (val.second == k-1)){
                    while(!que.empty())que.pop();
                    return level[val.first][val.second];
                }
                que.push(val);

            }
        }
    }
    return -1;

}

void fired_BFS(pii node,map<pii,vector<pii> >&network){
    refresh();
    checked[node.first][node.second]=true;
    level[node.first][node.second]=0;
    que.push(node);
    while(!que.empty()){
        pii n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            pii val=network[n][i];
            if(checked[val.first][val.second]==false){
                checked[val.first][val.second]=true;
                if(level[val.first][val.second]>level[n.first][n.second]+1)
                    level[val.first][val.second]=level[n.first][n.second]+1;
                que.push(val);

            }
        }
    }


}

void refresh(){
    for(int i=0;i<205;i++)for(int j=0;j<205;j++)checked[i][j]=false;
}

void make_relation(pii position,pii bounds,map<pii,vector<pii>>& network){

    for(int i=0;i<4;i++){
        int rows=row[i]+position.first;
        int cols=col[i]+position.second;

        if(rows>=0 && cols>=0 && rows<bounds.first && cols <bounds.second){
            if(arr[rows][cols]!='#')network[position].pb({rows,cols});
        }
    }
}

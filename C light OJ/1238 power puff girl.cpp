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
int rows[]={0,-1,0,1};
int cols[]={-1,0,1,0};

map<pii,bool> checked;
map<pii,int>level;
queue<pii>que;
void make_relation(map<pii,vector<pii> > &network,string arr[],int row,int col);
int BFS(pii node,map<pii,vector<pii> > network,pii home);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;
    pair<int,int> home;

    cin>>test;
    while(test--){
        scanf("%d %d",&m,&n);
        map<pii,vector<pii> > network;
        vector<pair<int,int> > us;
        cin.ignore();
        string arr[m+5];
        for(i=0;i<m;i++)  cin>>arr[i];

        for(i=1;i<m-1;i++){
            for(j=1;j<n-1;j++){
                make_relation(network,arr,i,j);

                if(arr[i][j]=='a' || arr[i][j]=='b' || arr[i][j]=='c')us.pb({i,j});
                else if(arr[i][j]=='h')home = mp(i,j);
            }
        }
        for(i=0,cnt=0;i<3;i++){

            cnt=max(cnt,BFS(us[i],network,home));
        }
        printf("Case %d: %d\n",++t,cnt);

    }

    //free();   //if pointer array
    return 0;
}

void make_relation(map<pii,vector<pii> > &network,string arr[],int row,int col){
    int n_row,n_col;
    if(arr[row][col]!='#' && arr[row][col]!='m')
        for(int i=0;i<4;i++){
            n_row = row+rows[i];
            n_col = col+cols[i];
            if(arr[n_row][n_col]=='.' ||arr[n_row][n_col]=='a' || arr[n_row][n_col]=='b' || arr[n_row][n_col]=='c' || arr[n_row][n_col]=='h'){
                network[{row,col}].pb({n_row,n_col});
            }
    }


}

int BFS(pii node,map<pii,vector<pii> > network,pii home){
    checked.clear();
    level.clear();
    checked[node]=true;
    level[node]=0;
    que.push(node);
    while(!que.empty()){
        pii n=que.front();
        que.pop();
        int len=network[n].size();

        for(int i=0;i<len;i++){
            pii val=network[n][i];
            if(checked[val]==false){
                checked[val]=true;
                level[val]=level[n]+1;
                que.push(val);

            }
        }
    }

   return level[home];

}

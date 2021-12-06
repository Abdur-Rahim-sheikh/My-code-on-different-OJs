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

bool checked[1002][1002];
int R, C;
queue <pair<int,int> > que;
int level[1005][1005];

void BFS(int r1,int c1,int r2,int c2,map<pair<int,int>,vector<pair<int,int> > >network);
int main ()
{
    int i,j,k,r1,c1,r2,c2;
    int rowRelates[10]={1,-1,0,0};
    int colRelates[10]={0,0,-1,1};
    while ( scanf ("%d %d", &R, &C) ) {
        if ( R == 0 && C == 0 ) break;



      map<pair<int,int>,vector<pair<int,int> > >network;

        int r;
        scanf ("%d", &r);

        for ( int i = 0; i < r; i++ ) {
            int row;
            scanf ("%d", &row);

            int mines;
            scanf ("%d", &mines);

            for ( int j = 0; j < mines; j++ ) {
                int pos;
                scanf ("%d", &pos);
                checked[row][pos] = true;
            }
        }

        for(i=0;i<R;i++){
        for(j=0;j<C;j++){
            for(k=0;k<4;k++){
                    int r=i+rowRelates[k],c=j+colRelates[k];
                if(checked[r][c]==false && r >= 0 && r <= R && c >= 0 && c <= C ){
                    network[make_pair(i,j)].push_back(make_pair(r,c));
                }
            }
            checked[i][j]=false;
        }
      }
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

        BFS(r1,c1,r2,c2,network);
        printf("%d\n",level[r2][c2]);

    }

    return 0;
}
void BFS(int r1,int c1,int r2,int c2,map<pair<int,int>,vector<pair<int,int> > >network){
    checked[r1][c1]=true;
    level[r1][c1]=0;
    que.push(make_pair(r1,c1));
    while(!que.empty()){
        pair<int,int> n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            pair<int,int> val=network[n][i];
            if(checked[val.first][val.second]==false){
                checked[val.first][val.second]=true;
                level[val.first][val.second]=level[n.first][n.second]+1;

                if(val.first==r2 && val.second==c2){
                    while(!que.empty())que.pop();
                    return;
                }
                que.push(val);

            }
        }
    }


}

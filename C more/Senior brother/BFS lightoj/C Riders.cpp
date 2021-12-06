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

int row[]={1,1,2,2,-1,-1,-2,-2};
int col[]={2,-2,1,-1,2,-2,1,-1};
int arr[20][20];
map<pii,bool> checked;
map<pii,int> level;
queue<pii>que;

int BFS(pii node,map<pii,vector<pii> > &network);
void make_relation(pii position,pii area,string field[],map<pii,vector<pii> >&network);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;


    cin>>test;
    while(test--){
        scanf("%d %d",&m,&n);
        map<pii,vector<pii> >network;
        vector<pii>riders;

        string field[m+5];
        for(i=0;i<m;i++)cin>>field[i];
        for(i=0,cnt=0;i<m;i++){

            for(j=0;j<n;j++){
                make_relation({i,j},{m,n},field,network);
                if(field[i][j]>='1' && field[i][j]<='9'){
                    riders.pb({i,j});
                    arr[i][j]=field[i][j]-'0';
                    cnt++;
                }
                else arr[i][j]=0;
            }
        }


        int sum,prev=INF,len=riders.size();

        for(i=0;i<m;i++)
        for(int k=0;k<n;k++){
            pii pos =mp(i,k);

            int got = BFS(pos,network);

            ///if(got != cnt-1) break;
            if(got == cnt){
                for(j=0,sum=0;j<len;j++){
                   // if(i==j)continue;

                    pii cell= riders[j];


                    sum+=(level[cell]/arr[cell.first][cell.second] + (level[cell]%arr[cell.first][cell.second]>0?1:0));

                }

                if(sum<prev)prev=sum;
            }
        }
        if(len==0)printf("Case %d: 0\n",++t);
        else if(prev==INF)printf("Case %d: -1\n",++t);
        else printf("Case %d: %d\n",++t,prev);

    }



    //free();   //if pointer array
    return 0;
}

int BFS(pii node,map<pii,vector<pii> > &network){
    checked.clear();
    checked[node]=true;
    level[node]=0;
    int cnt=0;
    if(arr[node.first][node.second]>0)cnt++;
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
                if(arr[val.first][val.second]>0)cnt++;
            }
        }
    }

   return cnt;

}

void make_relation(pii position,pii area,string field[],map<pii,vector<pii> >&network){
    for(int i=0;i<8;i++){
        int rows=position.first+row[i];
        int cols=position.second+col[i];
        if(rows>=0 && cols>=0 && rows<area.first && cols<area.second){
            network[position].pb({rows,cols});
        }

    }


}

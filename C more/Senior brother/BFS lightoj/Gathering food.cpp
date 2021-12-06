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
string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<pii,bool> checked;
map<pii,int> level;
queue<pii>que;
pii BFS(int ith,pii node,map<pii,vector<pii> >&network,string arr[]);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,food;
    int row[7]={-1,0,1,0};
    int col[7]={0,1,0,-1};
    cin>>test;

    while(test--){
        scanf("%d",&n);
        string arr[n+5];
        map<pii,vector<pii> > network;

        for(i=0;i<n;i++)cin>>arr[i];
        pii start,stop;
        for(i=0,food=0;i<n;i++)
            for(j=0;j<n;j++){

               if(arr[i][j]>='A' && arr[i][j]<='Z')food++;

                if(arr[i][j]=='A')start = mp(i,j);


               if(arr[i][j]!='#') for(k=0;k<4;k++){
                    int rows = i+row[k];
                    int cols = j+col[k];

                    if(rows>=0 && rows<n && cols>=0 && cols<n && arr[rows][cols]!='#'){
                        network[{i,j}].pb({rows,cols});
                    }
                }
            }
            pii got=start;
            for(i=1,level[start]=0;i<food;i++){
                got=BFS(i,got,network,arr);
                if(got.first==-1 && got.second== -1)break;
            }


             if (i<food) printf("Case %d: Impossible\n",++t);

             else printf("Case %d: %d\n",++t,level[got]);


    }



    //free();   //if pointer array
    return 0;
}




pii BFS(int ith,pii node,map<pii,vector<pii> >&network,string arr[]){
    checked.clear();

    checked[node]=true;

    que.push(node);
    while(!que.empty()){
        pii n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            pii val=network[n][i];
            if(arr[val.first][val.second]>='A' && arr[val.first][val.second]<='Z'){
                if(arr[val.first][val.second]==alpha[ith]){
                    level[val]=level[n]+1;
                    while(!que.empty())que.pop();
                    return val;
                }
                else if(arr[val.first][val.second]<alpha[ith]);

                else continue;
            }
            if(checked[val]==false){
                checked[val]=true;
                level[val]=level[n]+1;
               // cout<<level[val]<<' '<<val.first<<' '<<val.second<<endl;

                que.push(val);

            }
        }
    }
    return {-1,-1};

}

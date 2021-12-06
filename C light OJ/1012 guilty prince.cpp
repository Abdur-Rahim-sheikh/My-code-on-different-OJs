#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
using namespace std;
map<int,bool> checked;
int total;
queue<int>que;

void BFS(int node,vector<int> network[]);
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test,start;
    cin>>test;
    int row[7]={-1,0,1,0};
    int col[7]={0,1,0,-1};
    while(test--){
        vector<int>network[1000];
        bool arr[50][50]={0};
        total=0;
        checked.clear();
        string s;
        scanf("%d %d",&m,&n);

        for(i=1;i<=n;i++){
            cin>>s;
            s='R'+s;
            for(j=1;j<=m;j++){
                if(s[j]=='.')arr[i][j]=true;
                else if(s[j]=='@')arr[i][j]=true,start=i*m+j;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                ///making relation of a cell with other

               if(arr[i][j]==true)
                for(k=0;k<4;k++){
                    int a=row[k]+i;
                    int b=col[k]+j;
                    if(arr[a][b]==true)  network[i*m+j].pb(a*m+b);

               }

            }
        }
        BFS(start,network);
        printf("Case %d: %d\n",++t,total);

    }

    //free();   //if pointer array
    return 0;
}


void BFS(int node,vector<int> network[]){
    checked[node]=true;
    total++;
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=network[n].size();

        for(int i=0;i<len;i++){
            int val=network[n][i];

            if(checked[val]==false){
                checked[val]=true;
                total++;
                que.push(val);

            }
        }
    }


}


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

vector<int>nodes[1000];

bool checked[1000];
int color[1000];
queue<int> que;
bool BFS(int surc);
int main()
{

    int i,j,k,m,n,val,t=0,test,a,b;
    while(cin>>n && n!=0){
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }
        if(BFS(0)==false)  printf("NOT BICOLORABLE.\n");

        else printf("BICOLORABLE.\n");

        //nodes.clear(vector::begin(),vector::end());

        for(i=0;i<n;i++){
            nodes[i].clear();
            checked[i]=false;
            color[i]=0;
        }






    }
    //free();   //if pointer array
    return 0;
}

bool BFS(int surc){
    color[surc]=0;
    checked[surc]=true;
    que.push(surc);
    while(!que.empty()){
        int val=que.front();
        que.pop();

        int len=nodes[val].size();
        for(int i=0;i<len;i++){
            int present=nodes[val][i];
            if(checked[present]==false){
                checked[present]=true;
                que.push(present);
                color[present]=(color[val]==0)?1:0;

            }
            else if(checked[present]==true && color[val]==color[present])return false;

               // printf("%d %d\n",present,level[present]);

        }
    }
    return true;

}

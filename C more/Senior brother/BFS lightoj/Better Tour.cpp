#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<stack>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
map<int,bool> checked;
map<int,int> level;
queue<int>que;

void BFS(int node,int stop,map<int,vector<int> >&network);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,last;

    cin>>test;
    while(test--){
        scanf("%d %d",&n,&last);
        int first=last;
        map<int,vector<int> >network;
        checked.clear();
        for(i=1;i<n;i++){
            scanf("%d",&val);
            network[val].pb(last);
            network[last].pb(val);
            last=val;
        }
        BFS(first,last,network);
        int go=last;
        stack<int> print;
        ///efficient backtracking push last node to first node then in stack then pop.
        while(level[go]!=0)print.push(go),go=level[go]; ///This go is parent of go node means next node
        print.push(go);
        int len =print.size();
        printf("Case %d:\n",++t);
        while(len>1){
            printf("%d ",print.top());
            print.pop();
            len--;
        }
       // printf("%d\n",go);
       printf("%d\n",print.top());
       print.pop();
    }



    //free();   //if pointer array
    return 0;
}




void BFS(int node,int stop,map<int,vector<int> >&network){
    checked[node]=true;
    level[node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        sort(network[n].begin(),network[n].end()); ///this help to find lexicographically shorted way.
        int len=network[n].size();
        for(int i=0;i<len;i++){
            int val=network[n][i];
            if(checked[val]==false){
                checked[val]=true;
                level[val]=n;
                if(val==stop){
                    while(!que.empty())que.pop();
                    return;
                }
                que.push(val);

            }
        }
    }


}

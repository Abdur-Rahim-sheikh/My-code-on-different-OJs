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
const int N=405;
vector<int>train_network[N],bus_network[N];
vector<int>::iterator it;
bool checked[N],train_passed,bus_passed;
int train_level[N],bus_level[N];
queue<int>que;
void train_BFS(int start,int dest);
void bus_BFS(int start,int dest);
int main()
{

    int i,j,k,m,n,val,t=0,test,a,b;

    cin>>n>>m;
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        train_network[a].push_back(b);
        train_network[b].push_back(a);
    }

     ///pushing values where train line is absence between two city
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){

            if(i==j)continue;
            it=find(train_network[i].begin(),train_network[i].end(),j);
            if(it==train_network[i].end()){
                bus_network[i].push_back(j);

                cout<<i<<' '<<j<<endl;
            }

        }
        cout<<bus_network[i].size()<<endl;
    }

    train_BFS(1,n);

    ///if train fail to reach the destination then no need to check further
    if(train_passed==false){
        cout<<-1<<endl;
        return 0;
    }


    bus_BFS(1,n);

    ///If  two veichle passes then greater value is the ans.
    if(bus_passed== true && train_passed==true)
        cout<<max(train_level[n],bus_level[n])<<endl;

    else cout<<-1<<endl;

   /* for(i=1;i<=n;i++){
        train_network[i].clear();
        bus_network[i].clear();
        checked[i]=false;
        bus_level[i]=train_level[i]=0;
    }
    */
    //free();   //if pointer array
    return 0;
}

void train_BFS(int start,int dest){
    checked[start]=true;
    train_level[start]=0;
    que.push(start);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=train_network[n].size();
        for(int i=0;i<len;i++){
            int val=train_network[n][i];
            if(checked[val]==false){
                checked[val]=true;
                train_level[val]=train_level[n]+1;

                que.push(val);

                if(val==dest)train_passed=true;
            }
        }
    }

}

void bus_BFS(int start,int dest){

    checked[start]=true;
    bus_level[start]=0;
    que.push(start);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=bus_network[n].size();
        for(int i=0;i<len;i++){
            int val=bus_network[n][i];
            if(checked[val]==false){
                checked[val]=true;
                bus_level[val]=bus_level[n]+1;
                que.push(val);
                // cout<<val<<' '<<bus_level[val]<<endl;
                if(val==dest){

                    bus_passed=true;

                    return;
                }
            }
            else{ ///if checked true
                if(train_level[val]!=bus_level[n]+1  || val==dest){
                    bus_level[val]=bus_level[n]+1;
                    que.push(val);
                    if(val==dest){
                        bus_passed=true;
                        return;
                    }
                }
            }
        }
    }

}

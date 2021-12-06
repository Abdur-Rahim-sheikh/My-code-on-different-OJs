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

vector<int>friends[3000];
int level[3000];
int amountOfLevel[3000];
bool checked[3000];
queue<int> que;
void BFS(int surc);
int main()
{

    int i,j,k,m,n,val,t=0,test,prev,save;
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d",&val);
            friends[i].push_back(val);
        }
    }
    cin>>test;
    while(test--){
        scanf("%d",&val);
        BFS(val);

        for(i=0,prev=0,save=0;i<n;i++){
            if(amountOfLevel[i]>prev){
                prev=amountOfLevel[i];
                save=i;
            }
        }

        if(save==0)printf("0\n");
        else{
            printf("%d %d\n",prev,save);
        }

        ///refereser
        for(i=0;i<n;i++){
            level[i]=0;
            amountOfLevel[i]=0;
            checked[i]=false;
        }
    }
    //free();   //if pointer array
    return 0;
}

void BFS(int surc){
    level[surc]=0;
    checked[surc]=true;
    que.push(surc);
    while(!que.empty()){
        int val=que.front();
        que.pop();

        int len=friends[val].size();
        for(int i=0;i<len;i++){
                int present=friends[val][i];
            if(checked[present]==false){

                checked[present]=true;
                level[present]=level[val]+1;

                amountOfLevel[level[present]]++;
                que.push(present);

               // printf("%d %d\n",present,level[present]);
            }
        }
    }

}

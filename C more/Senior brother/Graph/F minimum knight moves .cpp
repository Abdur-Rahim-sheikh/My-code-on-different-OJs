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
vector<int> OneDChess[300];
queue<int> que;
bool checked[1000];
int level[1000];

int BFS(int in,int dest);
int main()
{

    int i,j,k,m,n,val,t=0,test,r,c;
    int x[10]={2,2,-2,-2,1,1,-1,-1};
    int y[10]={1,-1,1,-1,2,-2,2,-2};
    ///making 2D chase board 1D by multiplying
    ///but before that save the coordinates of tree as edges.debt to geeksforgeeks.
    for(r=1;r<=8;r++){
        for(c=1;c<=8;c++){
            int val=8*(c-1)+r;
            for(k=0;k<8;k++){
                int r1=r+x[k];
                int c1=c+y[k];
                if(r1>0 && r1<=8 && c1>0 && c1<=8){
                    int position=8*(c1-1)+r1;
                    OneDChess[val].push_back(position);
                }

            }

        }

    }
    char ch1,ch2;
    int a,b;
    while(scanf("%c%d %c%d",&ch1,&a,&ch2,&b)==4){
        getchar();
        int from=(ch1-'a')*8+a;
        int to=(ch2-'a')*8+b;
       // cout<<from<<' '<<to<<endl;
        int moves=BFS(from,to);
        printf("To get from %c%d to %c%d takes %d knight moves.\n",ch1,a,ch2,b,moves);

        for(i=0;i<100;i++){
            checked[i]=false;
            level[i]=0;
        }
    }
    //free();   //if pointer array
    return 0;
}

int BFS(int in,int dest){
    checked[in]=true;
    level[in]=0;
    que.push(in);
    if(in==dest)return 0;
    while(!que.empty()){
        int val=que.front();
        que.pop();
        int len=OneDChess[val].size();
        for(int i=0;i<len;i++){
            int n=OneDChess[val][i];
            if(checked[n]==false){
                checked[n]=true;
                que.push(n);
                level[n]=level[val]+1;

                //cout<<level[n]<<endl;
                if(n==dest){
                    while(!que.empty()){
                        que.pop();
                    }
                    return level[n];
                }
            }
        }
    }

}

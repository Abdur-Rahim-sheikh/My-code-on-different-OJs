#include<bits/stdc++.h>
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
int row[]={0,-1,0,1};
int col[]={-1,0,1,0};

map<pii,bool> checked;
map<pii,int> level;
map<pii,bool>crystal;
queue<pii>que;
char area[505][505];
int BFS(pii node,map<pii,vector<pii> >&network,int ith_tree);
void make_relation(pii position,pii bounds,map<pii,vector<pii>>& network);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,a,b;

    cin>>test;
    while(test--){
        scanf("%d %d %d",&m,&n,&k);

        map<pii,vector<pii> > network;
        crystal.clear();
        checked.clear();
        cin.ignore();
        for(i=0;i<m;i++)cin>>area[i];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){

                if(area[i][j]!='#')make_relation({i,j},{m,n},network);
                if(area[i][j]=='C')crystal[{i,j}]=true;
            }
        }


        int ith,arr[1000];
        printf("Case %d:\n",++t);
        for(i=0,ith=0;i<k;i++){
           scanf("%d %d",&a,&b);
           /// cin>>a>>b;
            a--;
            b--;
            if(checked[{a,b}]==false){

                arr[ith]=BFS({a,b},network,ith);
                ith++;
             //   cout<<arr[ith-1]<<' '<<a<<' '<<b<<endl;
            }
            printf("%d\n",arr[level[{a,b}]]);
        }


    }


    //free();   //if pointer array
    return 0;
}

int BFS(pii node,map<pii,vector<pii> >&network,int ith_tree){
    int total=0;
    checked[node]=true;
    if(crystal[node]==true)total++;
    level[node]=ith_tree;
    que.push(node);
    while(!que.empty()){
        pii n=que.front();
        que.pop();
        int len=network[n].size();
        for(int i=0;i<len;i++){
            pii val=network[n][i];
            if(checked[val]==false){
                if(crystal[val]==true)total++;
                checked[val]=true;
                level[val]=ith_tree;
                que.push(val);

            }
        }
    }
    return total;

}

void make_relation(pii position,pii bounds,map<pii,vector<pii>>& network){

    for(int i=0;i<4;i++){
        int rows=row[i]+position.first;
        int cols=col[i]+position.second;

        if(rows>=0 && cols>=0 && rows<bounds.first && cols <bounds.second){
            if(area[rows][cols]!='#')network[position].pb({rows,cols});
        }
    }
}

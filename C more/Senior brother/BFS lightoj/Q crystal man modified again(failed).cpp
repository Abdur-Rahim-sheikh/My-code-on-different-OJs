#include<bits/stdc++.h>
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
int row[]={0,-1,0,1};
int col[]={-1,0,1,0};

/**here i will not make any vector in real
but will surf node to node using the for loop
means in bfs i will dynamically choose adjacent node (idea taken from shuvo vai)*/

map<pii,bool> checked;
map<pii,int> level;
queue<pii>que;
string area[502];
int BFS(pii node,pii bounds,int ith_tree);
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test,a,b;

    cin>>test;
    while(test--){
        scanf("%d %d %d",&m,&n,&k);



        checked.clear();
        level.clear();
        for(i=0;i<m;i++)cin>>area[i];

        int ith,arr[50000];

        printf("Case %d:\n",++t);
        for(i=0,ith=0;i<k;i++){
           scanf("%d %d",&a,&b);

            a--;
            b--;
            if(checked[{a,b}]==false){

                arr[ith]=BFS({a,b},{m,n},ith);
                ith++;

            }
            printf("%d\n",arr[level[{a,b}]]);
        }


    }


    //free();   //if pointer array
    return 0;
}

int BFS(pii node,pii bounds,int ith_tree){
    int total=0;
    checked[node]=true;
    if(area[node.first][node.second]=='C')total++;
    level[node]=ith_tree;
    que.push(node);
    while(!que.empty()){
        pii n=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int rows=row[i]+n.first;
            int cols=col[i]+n.second;
            if(rows>=0 && cols>=0 && rows<bounds.first && cols <bounds.second && area[rows][cols]!='#'){
                pii val=mp(rows,cols);
                if(checked[val]==false){
                    if(area[val.first][val.second]=='C')total++;
                    checked[val]=true;
                    level[val]=ith_tree;
                    que.push(val);

                }
            }
        }
    }
    return total;

}

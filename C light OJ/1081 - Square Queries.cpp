#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
int table[20][505][505];
void sparse(int n){
    int a,b;
    for(int k=0;(1<<k)<=n;k++){
        int p=1<<k;
        int r=(p<<1)-1;
        for(int i=1;i+r<=n;i++){
            for(int j=1;j+r<=n;j++){
                a=max(table[k][i][j],table[k][i][j+p]);
                b=max(table[k][i+p][j],table[k][i+p][j+p]);
                table[k+1][i][j]=max(a,b);
            }
        }
    }
    return;
}
int main(){
    int i,j,k,n,m,t=0,p,q,test,val;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n>>m;

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&table[0][i][j]);
            }
        }

        sparse(n);
        printf("Case %d:\n",++t);
        for(i=0;i<m;i++){
            scanf("%d %d %d",&p,&q,&k);
            int r=log2(k);
            int left=k-(1<<r);
            int a=max(table[r][p][q],table[r][p][q+left]);
            int b=max(table[r][p+left][q],table[r][p+left][q+left]);
            printf("%d\n",max(a,b));
        }

    }
    //free();   //if pointer array
    return 0;
}

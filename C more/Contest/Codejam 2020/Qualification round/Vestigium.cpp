#include<bits/stdc++.h>

#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("showing %d\n",n)
#define p2(m,n) printf("showing %d %d\n",m,n)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mt make_tuple
#define pb push_back
//#define tcii tuple <char,int,int>
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

int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        int sum=0;
        bool r[n+5][n+5],c[n+5][n+5];
        memset(r,false,sizeof r);
        memset(c,false,sizeof c);
        set<int>row,col;

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&val);
                if(i==j)sum+=val;
                if(r[i][val])row.insert(i);
                if(c[j][val])col.insert(j);
                r[i][val]=true;
                c[j][val]=true;
            }
        }
        printf("Case #%d: %d %d %d\n",++t,sum,row.size(),col.size());
    }
    //free();   //if pointer array
    return 0;
}

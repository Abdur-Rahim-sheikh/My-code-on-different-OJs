#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define p1(n) printf("showing %d\n",n)
#define p2(m,n) printf("showing %d %d\n",m,n)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
int arr[202][101],cnt[101];
map<int,int>wom;
map<int,bool>man;
int unmarried(int n){
    int i;
    for(i=1;i<=n;i++)if(man[i]==false)return i;
    return 0;
}
int main(){
    int i,j,n,t=0,test,v;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>n;
        memset(cnt,0,sizeof cnt);
        wom.clear();
        man.clear();
        for(i=1;i<=n;i++)for(j=1;j<=n;j++)scanf("%d",&arr[i][j]);
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%d",&v);
            arr[i+n][v]=j;
        }
        while(true){
            int m=unmarried(n);
            //p1(m);
            if(!m)break;
            int w=arr[m][++cnt[m]];
            int her=wom[w];
            //p2(w,her);
            if(her==0 or arr[w][her]>arr[w][m]){
                man[her]=false;
                man[m]=true;
                wom[w]=m;
            }
        }
        printf("Case %d:",++t);
        for(i=n+1;i<=2*n;i++){
            printf(" (%d %d)",wom[i],i);
        }
        printf("\n");
    }
    //free();   //if pointer array
    return 0;
}

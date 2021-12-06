#include<bits/stdc++.h>
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

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>m>>n;
    vector<int>v(n,0);
    int mex=0;
    for(i=0;i<m;i++){
        scanf("%d",&val);
        v[val%n]++;
        while(v[mex%n])v[mex%n]--,mex++;
        printf("%d\n",mex);
    }
    //free();   //if pointer array
    return 0;
}

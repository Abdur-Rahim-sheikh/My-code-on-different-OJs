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
#define vi vector<int>
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>n>>m;
    vector<vi> left(n,vi(m,1)),right(n,vi(m,1)),up(n,vi(m,1)),down(n,vi(m,1)),lr(n,vi(m,1));
    string s[n];
    for(i=0;i<n;i++)cin>>s[i];
    //left
    for(i=1;i<n-1;i++){
        for(j=1;j<m-1;j++){
            if(s[i][j]==s[i][j-1])left[i][j]+=left[i][j-1];
        }
    }
    //right
    for(i=1;i<n-1;i++){
        for(j=m-2;j>0;j--){
            if(s[i][j]==s[i][j+1])right[i][j]+=right[i][j+1];
            lr[i][j]=min(left[i][j],right[i][j]);
        }
    }
    //up
    for(i=1;i<n-1;i++){
        for(j=1;j<m-1;j++){
            if(s[i][j]==s[i-1][j]){
                up[i][j]=min(lr[i][j],lr[i-1][j]+1);
                up[i][j]=min(up[i][j],up[i-1][j]+1);
            }
        }
    }
    //down & final
    int ans=0;
    for(i=n-2;i>0;i--){
        for(j=1;j<m-1;j++){
            if(s[i][j]==s[i+1][j]){
                down[i][j]=min(lr[i][j],lr[i+1][j]+1);
                down[i][j]=min(down[i][j],down[i+1][j]+1);
            }
            ans+=min(down[i][j],up[i][j]);
        }
    }
    int outmostSquare=2*(n+m)-4;
    if(n==1 or m==1)outmostSquare=max(n,m);
    cout<<ans+outmostSquare<<endl;
    //free();   //if pointer array
    return 0;
}

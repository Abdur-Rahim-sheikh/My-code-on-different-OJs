#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;
const int mm=505;
int lft[mm][mm],up[mm][mm];
int dp[mm][mm];
int solve(int i, int j) {
  if (i < 0 || j < 0)
    return 0;

  if (dp[i][j] != -1)
    return dp[i][j];

  return dp[i][j] = max(solve(i - 1, j) + lft[i][j], solve(i, j - 1) + up[i][j]);

}
int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        cin>>m>>n;

        for(i=0;i<m;i++)for(j=0;j<n;j++)scanf("%d",&lft[i][j]);
        for(i=0;i<m;i++)for(j=0;j<n;j++)scanf("%d",&up[i][j]);

        for(i=0;i<m;i++)for(j=0;j<n;j++)if(j)lft[i][j]+=lft[i][j-1];
        for(i=0;i<m;i++)for(j=0;j<n;j++)if(i)up[i][j]+=up[i-1][j];

        memset(dp,-1,sizeof dp);
        solve(m-1,n-1);
        printf("Case %d: %d\n",++t,dp[m-1][n -1]);
    }
    //free();   //if pointer array
    return 0;
}

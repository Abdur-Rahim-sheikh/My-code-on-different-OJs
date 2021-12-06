#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
//int row[4]={0,-1,0,1};
//int col[4]={-1,0,1,0};
using namespace std;
int dp[1<<17],n;
int arr[20][20];
int solve(int msk){
    if(msk==(1<<n)-1)return 0;
    if(dp[msk]!=(-1))return dp[msk];
    int mini=INF;
    for(int i=0;i<n;i++){
        if(!(msk&(1<<i))){
            int sum=arr[i][i];
            for(int j=0;j<n;j++){
                if((msk&(1<<j))>0 && i!=j)sum+=arr[i][j];
            }
            //cout<<sum<<endl;
            mini= min(mini,sum+solve((msk|(1<<i))));
        }
    }
    dp[msk]=mini;
    return mini;
}
int main(){
    int i,j,k,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)scanf("%d",&arr[i][j]);
        }
        memset(dp,-1,sizeof dp);
        int ans=solve(0);
        printf("Case %d: %d\n",++t,ans);
    }
    //free();   //if pointer array
    return 0;
}

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
ll dp[35][35];
ll ncr(int n,int r){
    if(n==r || r==0)return 1;
    else if(r==1)return n;
    else if(dp[n][r]!=(-1))return dp[n][r];
    dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
    return dp[n][r];

}
int main(){

    int i,j,k,m,n,r,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    memset(dp,-1,sizeof dp);
    ll fact[20];
    fact[0]=fact[1]=1;
    for(i=2;i<=20;i++)fact[i]=i*fact[i-1];

    cin>>test;
    while(test--){
        scanf("%d %d",&n,&r);
        ll res=0;
        if(n>=r) res=ncr(n,r);
        printf("Case %d: %lld\n",++t,res*res*fact[r]);
    }
    //free();   //if pointer array
    return 0;
}

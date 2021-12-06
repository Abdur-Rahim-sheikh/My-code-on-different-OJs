#include<iostream>
#include<string>
#include<vector>
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
ll arr[20][20];
ll dp[1<<17];
ll bit_mask(int n){
    memset(dp,0,sizeof dp);
    ///here position of one's of mask denotes selected column for
    ///number of (one's) men
    for(int msk=0;msk<(1<<n);msk++){
        int x=0;
        x=__builtin_popcount(msk);
        ///first x-1 person are selected.
        for(int j=0;j<n;j++){
            if(!(msk&(1<<j))){
                dp[msk|(1<<j)]=max(dp[msk|(1<<j)],dp[msk]+arr[x][j]);
            }

        }
    }
    return dp[((1<<n)-1)];
}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%d",&n);
        for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%lld",&arr[i][j]);

        printf("Case %d: %lld\n",++t,bit_mask(n));
    }
    //free();   //if pointer array
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,test,t=0;
    cin>>test;
    string s;
    while(test--){
        cin>>s;
        int len=s.size();
        long long dp[len][len];
        memset(dp,0,sizeof dp);
        for(i=0;i<len;i++)dp[i][i]=1;
        for(i=1;i<len;i++){
            for(j=0;j+i<len;j++){
                k=i+j;
                if(s[j]==s[k])dp[j][k]=1+dp[j+1][k]+dp[j][k-1];
                else dp[j][k]=dp[j+1][k]+dp[j][k-1]-dp[j+1][k-1];
            }
        }
        printf("Case %d: %lld\n",++t,dp[0][len-1]);
    }
}

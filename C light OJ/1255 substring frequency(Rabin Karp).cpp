#include<bits/stdc++.h>
#define ll long long
using namespace std;
///Rabin Karp is going to implement.
#define MOD 1000000007
ll power[1000005];

ll pre[1000005];
int rabinKarp(string s,string sub){
    ll len=sub.size();
    ll n=s.size();
    ll key,i,k;
    int cnt;
    for(i=0,key=0;i<len;i++){
        k=sub[i]-'a'+1;
        key=(key+(k*power[i])%MOD)%MOD;
    }
    pre[0]=0;
    for(i=0;i<n;i++){
        k=s[i]-'a'+1;
        pre[i+1]=(pre[i]+k*power[i])%MOD;
    }
    for(i=0,cnt=0;i+len<=n;i++){
        ll tem=(pre[i+len]-pre[i]+MOD)%MOD;
        if(tem==(key*power[i])%MOD)cnt++;
    }
    return cnt;
}
int main()
{

    int i,j,k,m,n,t=0,cnt=0,test;
    int val;
    string s,sub;
    //freopen("000input.txt","r",stdin);
    power[0]=1;
    for(i=1;i<1000005;i++)power[i]=(power[i-1]*33)%MOD;
    cin>>test;
    while(test--){
        cin>>s>>sub;

        printf("Case %d: %d\n",++t,rabinKarp(s,sub));
    }
    //free();   //if pointer array
    return 0;
}

#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare prllf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;

int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    string s,ch;
    cin>>n>>m;
    cin>>s>>ch;
    ll arr[m+5],mod=998244353;
    arr[0]=1;
    for(i=1;i<m;i++){
        arr[i]=arr[i-1]+ch[i]-'0';
    }
    ll power[n+5];
    k=1;
    for(i=n-1;i>=0;i--){
        power[i]=k;
        k=(k*2)%mod;
    }
    ll sum=0;
    k=m-n;
    for(i=0;i<n;i++){

            ll it=(i+k>=0)?arr[i+k]:0;
         if(s[i]=='1')sum=(sum+it*power[i])%mod;
    }
    printf("%lld\n",sum);
    //free();   //if poller array
    return 0;
}

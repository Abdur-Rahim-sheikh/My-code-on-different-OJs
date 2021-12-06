#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare prllf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define MAX 10000000
//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
// where is the prime in 2 to n and what(by index)
ll prime[MAX];
void seive(ll n)
{
	prime[0]=prime[1]=0;
	ll j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{
		if(prime[i]>0)continue;

		for(j=i*i;j<=n;j+=i) if(prime[j]==0)prime[j]=i;
	}
}

int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(MAX-1);
    for(i=2;i<MAX;i++){
        if(prime[i]==0)prime[i]+=i;
        prime[i]+=prime[i-1];
    }
    cin>>test;
    while(test--){
        cin>>n;
        printf("%lld\n",prime[n]);
    }
    //free();   //if poller array
    return 0;
}

#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;

// where is the prime in 2 to n and what(by index)
bool prime[10000007];
vector<ll> primo;
void seive(int n)
{
	prime[1]=1;
	int j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{
		if(prime[i]>0)
		continue;
		for(j=i*i;j<=n;j+=i) if(prime[j]==0)prime[j]=true;
	}
}
ll accu(ll n,ll cnt){
    ll sum=2*cnt+1,tem=n;
    for(ll i=1;i<=cnt;i++,tem*=n){
        sum+=tem*((cnt-i)*2+1);
    }
    return sum;
}
ll gcdsum(ll n){
    ll ans=1;
    for(ll i=0;i<primo.size() and primo[i]*primo[i]<=n;i++){
        if(n%primo[i]==0){
            int cnt=0;
            while(n%primo[i]==0)n/=primo[i],cnt++;
            ans*=accu(primo[i],cnt);
        }
    }
    if(n>1)ans*=accu(n,1);
    return ans;
}
int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(10000000);
    for(i=2;i<=10000000;i++)if(prime[i]==false)primo.pb(i);
    cin>>test;
    while(test--){
        cin>>n;
        printf("Case %lld: %lld\n",++t,gcdsum(n));
    }
    //free();   //if pointer array
    return 0;
}

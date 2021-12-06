#include<bits/stdc++.h>
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
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
// where is the prime in 2 to n and what(by index)
vector<ll> primo;
bool prime[100005];
void seive(ll n)
{
	for(ll i=2;i<=n;i++)
	{
		if(prime[i]>0) continue;
		primo.pb(i);

		for(ll j=i*i;j<=n;j+=i) if(prime[j]==0)prime[j]=true;
	}
}

int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(100001);

    cin>>test;
    while(test--){
        cin>>m>>n;
        ll k=__gcd(m,n);
        n/=k;
        ll ans=n,len=primo.size();
        for(i=0;i<len and primo[i]*primo[i]<=n;i++){
            bool sign=false;
            while(n%primo[i]==0)n/=primo[i],sign=true;
            if(sign)ans-=ans/primo[i];
        }
        if(n>1)ans-=ans/n;
        cout<<ans<<endl;
    }
    //free();   //if pointer array
    return 0;
}

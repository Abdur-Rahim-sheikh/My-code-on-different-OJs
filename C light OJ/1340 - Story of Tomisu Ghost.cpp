#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// where is the prime in 2 to n and what(by index)
bool prime[100005];
ll mod = 10000019;
void sieve(int n){
    for(int i=2;i*i<=n;i++){
		if(prime[i])continue;

		for(int j=i*i;j<=n;j+=i) if(prime[j]==0)prime[j]=true;
	}
}
ll recpower(ll n,int i){
    if(i==1)return n;
    ll sum=recpower(n,i/2);
    sum=(sum*sum)%mod;
    if(i&1)sum=(sum*n)%mod;
    return sum;
}
int main(){
    int i,j,k,m,val,t=0,test;
    ll n;
    //freopen("000input.txt","r",stdin);
    vector<int> primo;
    vector<ll>fact(100001);
    sieve(100000);
    fact[0]=fact[1]=1;
    for(i=2;i<=100000;i++){
        if(prime[i]==false)primo.pb(i);
        fact[i]=(fact[i-1]*i)%mod;
    }
    cin>>test;

    while(test--){
        cin>>n>>m;
        ll sum=1;
        if(m==1){
            printf("Case %d: %lld\n",++t,fact[n]);
            continue;
        }
        for(i=0;primo[i]*2<=n;i++){
            int cnt=0;
            ll k=primo[i];
            while(n/k){
                cnt+=(int)n/k;
                k*=primo[i];
            }
            if(cnt/m == 0)break;
            //p2(primo[i]*primo[i],cnt/m);
            sum=(sum*recpower(primo[i],cnt/m))%mod;
        }

        if(sum==1)printf("Case %d: -1\n",++t);
        else printf("Case %d: %lld\n",++t,sum);
    }
    //free();   //if pointer array
    return 0;
}

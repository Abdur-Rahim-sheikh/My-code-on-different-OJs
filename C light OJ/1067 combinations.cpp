#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<long long,long long>
using namespace std;
ll mod = 1000003;
ll mod_inverse(ll n);
pii extnuc(ll a,ll b);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test,big,small;
    ll fact[1000010];
    fact[0]=fact[1]=1;
    for(i=2;i<=1000000;i++) fact[i]=(fact[i-1]*i)%mod;
    cin>>test;
    while(test--){
        scanf("%lld %lld",&n,&m);

        if(m>n)printf("Case %lld: 0\n",++t);
        else if (m == n || m ==0 )printf("Case %lld: 1\n",++t);
        else{
            ll denominator = (fact[m]*fact[n-m])%mod;
            denominator = mod_inverse(denominator);
            ll result = (fact[n]*denominator)%mod;
            printf("Case %lld: %lld\n",++t,result);
        }

    }


    //free();   //if pointer array
    return 0;
}



//extented euclid function
pii extnuc(ll a,ll b){
	if(b==0) return pii(1,0);

	pii d =extnuc(b,a%b);
	return pii(d.second, (d.first - d.second*(a/b)) );
}

ll mod_inverse(ll n){
	pii d = extnuc(n,mod);
	return ((d.first%mod)+mod)%mod;
}

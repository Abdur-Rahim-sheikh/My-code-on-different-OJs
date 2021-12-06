#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pairii pair<int,int>
using namespace std;
ll GCD(ll m,ll n);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test;
    ll a,b,c,d;
    cin>>test;
    while(test--){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        ll x=abs(c-a),y=abs(d-b);
        if(x==0 || y==0)k=max(x,y);      /// if any of x ,y is zero
        else{
             k = GCD(x,y);
        }
        printf("Case %lld: %lld\n",++t,k+1);
    }
    //free();   //if pointer array
    return 0;
}

ll GCD(ll m,ll n)
{
	ll divisor,divident,rem=1;
	divident=(m>n?m:n);
	divisor=(m>n?n:m);

	while(rem!=0)
	{
		rem=divident%divisor;
		divident=divisor;
		divisor=rem;
	}

	return divident;      //which  actually carrying divisor value

}

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
using namespace std;
ll GCD(ll m,ll n);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test;

    cin>>n>>m>>j>>k;
    val=GCD(j,k);
    j/=val;
    k/=val;
    cout<<min(n/j,m/k)<<endl;
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

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
long long power(long long base,long long n,long mod){
    if(n==0)return 1;
    else if(n==1) return base%mod;

    if(n&1)return (power(base,n-1,mod)*base)%mod;
    else{
       long long x= power(base,n/2,mod);
        return (x*x)%mod;
    }
}
int main()
{

    ll i,j,k,m,n,val,t=0,test,mod;
    while(cin>>m>>n>>mod){

        printf("%lld\n",power(m,n,mod));
    }

    //free();   //if pointer array
    return 0;
}

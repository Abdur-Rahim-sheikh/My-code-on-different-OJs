
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
long long H( int n ) {
    long long res = 0;
    for( int i = 1; i <= n/2; i++ )
        res = res + n / i;
    return res;
}
int main()
{

    long long i,j,k,m,n,val,t=0,test;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&val);
        printf("Case %lld: %lld\n",i+1,H(val)+(val-val/2));
    }

    //free();   //if pointer array
    return 0;
}


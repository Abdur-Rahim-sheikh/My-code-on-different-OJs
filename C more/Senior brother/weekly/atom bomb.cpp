#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    ll i,j,val,t=0,test,k,m,n;

    cin>>test;
    while(test--){


        scanf("%lld %lld %lld",&k,&m,&n);

       ///geometric propagation  k+m*k+m*m*k+.........+(n+-lemda)
       ///n=k*m^n-1
       ///val=n-1=log m(n/k);==log10(n/k)/log10(m);
       ll p=n/k;
        val=log10(p)/log10(m);

        ///if initial value is greater then highest limit then solution =val will be negative but ans will be zero.
        if(val<0)val=0;
        printf("%lld\n",val);
    }
    //free();   //if pointer array
    return 0;
}


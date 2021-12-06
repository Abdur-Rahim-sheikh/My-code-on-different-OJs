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

    ll i,j,k,m,n,val,t=0,test;

    while(cin>>n && n>2){
            ll sum=0;
        for(i=1;i<n-2;i++){
            if(i&1)sum+=((i/2)+1)*((i/2)+1);
            else sum+=(i/2)*((i/2)+1);
        }
        printf("%lld\n",sum);
    }
    //free();   //if pointer array
    return 0;
}

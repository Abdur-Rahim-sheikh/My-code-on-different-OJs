#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    ll i,j,k,m,n,val,t=0,test,arr[100000]={0};

    scanf("%lld",&n);

    for(i=1;i<=n;i++){scanf("%lld",&val);arr[i]=arr[i-1]+val;}
    scanf("%lld",&n);
    while(n--){
        scanf("%lld %lld",&k,&m);
        printf("%lld\n",arr[m+1]-arr[k]);
    }
    //free();   //if pointer array
    return 0;
}

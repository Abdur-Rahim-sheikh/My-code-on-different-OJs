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

int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test,prev=INF;
    cin>>n;
     scanf("%lld %lld",&val,&m);
     prev=val;
    while(--n){
        scanf("%d %d",&val,&m);

        if(val<=prev) while(val<=prev)val+=m;
        prev=val;
    }
    printf("%lld",val);
    //free();   //if pointer array
    return 0;
}

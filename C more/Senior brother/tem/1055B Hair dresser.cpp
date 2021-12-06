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

    ll i,j,k,m,n,val,t=0,test,l,arr[200000],total=0;

    cin>>n>>m>>l;
    for(i=1;i<=n;i++){
         scanf("%lld",&arr[i]);
         if(arr[i]>l && arr[i-1]<=l)total++;
    }

    for(i=0;i<m;i++){
        scanf("%lld",&k);
        if(k){
                ll a,b;
            scanf("%lld %lld",&a,&b);
            if(arr[a]<=l && arr[a]+b>l)total+=1-(arr[a-1]>l)-(arr[a+1]>l);
            arr[a]+=b;
        }
        else{
            printf("%d\n",total);
        }
    }
    //free();   //if pointer array
    return 0;
}

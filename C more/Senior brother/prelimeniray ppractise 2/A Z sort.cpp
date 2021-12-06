#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
bool big(int a,int b){return a>b;}
int main()
{

    ll i,j,k,m,n,val,t=0,tt=0,test,arr[2][10000];
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%lld",&val);
        if(val&1) arr[1][t++]=val;
        else arr[0][tt++]=val;
    }
    sort(arr[1]+1,arr[1]+t,big);
    sort(arr[0],arr[0]+tt);
    val=max(t,tt);
    for(i=0;i<val;i++){
        if(i<t)printf("%lld ",arr[1][i]);
        if(i<tt)printf("%lld ",arr[0][i]);
    }

    //free();   //if pointer array
    return 0;
}

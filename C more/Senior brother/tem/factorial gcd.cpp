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

    ll i,j,k,m,n,val,t=0,test,ans=1;

    cin>>m>>n;
    val=min(m,n);
    for(i=2;i<=val;i++)ans*=i;
    cout<<ans<<endl;
    //free();   //if pointer array
    return 0;
}

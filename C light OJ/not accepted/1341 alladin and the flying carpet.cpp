#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

int main()
{

    ll i,j,k,m,n,val,t=0,cnt,test;

    cin>>test;
    while(test--){
        scanf("%lld %lld",&n,&i);
        cnt =0;
        while(i*i<n){ if(n%i==0)cnt++; i++;}
        printf("Case %lld: %lld\n",++t,cnt);
    }



    //free();   //if pointer array
    return 0;
}

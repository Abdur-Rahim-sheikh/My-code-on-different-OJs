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
#define pairii pair<int,int>
using namespace std;

int main()
{

    unsigned ll i,j,k,m,n,val,t=0,cnt=0,test;

    cin>>test;
    while(test--){
        scanf("%llu",&val);
        printf("Case %llu: ",++t);
        n=(val*10)/9;
        if(n%10==0)printf("%llu %llu\n",n-1,n);

        else printf("%llu\n",n);
    }


    //free();   //if pointer array
    return 0;
}

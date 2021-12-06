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

    ll i,j,k,m,n,val,t=0,cnt,test,rem=0;

    cin>>m>>n;
    ll sum=m+n;
    while(m>0 && n>0 ){
        i=sum%10;
        j=m%10;
        k=n%10;

        if(j == k && k == i && i == 0);
        else if(j ==0 || k == 0  || i==0 )break;
        sum/=10;
        m/=10;
        n/=10;

    }
    ///none is zero
    if(m*n>0)printf("NO\n");
    else printf("YES\n");


    //free();   //if pointer array
    return 0;
}

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

    int i,j,k,m,n,val,t=0,cnt=0,test;
    string a;
    cin>>n>>a;
    for(i=1;i<n;i++) if(a[i]!=a[i-1])break;

    if(i<n)printf("YES\n%c%c\n",a[i-1],a[i]);
    else printf("NO\n");
    //free();   //if pointer array
    return 0;
}

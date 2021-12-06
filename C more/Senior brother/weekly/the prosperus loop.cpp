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
    cin>>n;
    val=n&1;

    if(n<=36){
        for(i=0;i<n/2;i++)printf("8");
        if(val)printf("4");
        printf("\n");
    }
    else printf("-1\n");
    //free();   //if pointer array
    return 0;
}

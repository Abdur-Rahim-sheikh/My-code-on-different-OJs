#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
    int arr[40000];
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++) scanf("%d",&arr[i]);
    i=1;
    while(i<m) i=i+arr[i];

    if(i==m) printf("YES\n");
    else printf("NO\n");
    //free();   //if pointer array
    return 0;
}

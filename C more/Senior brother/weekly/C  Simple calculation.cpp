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
double arr[50000],c[50000];
double recurs(int i){

    if(arr[i]<INF) return arr[i];
    else arr[i]=((recurs(i-1)+recurs(i+1))/2.00)-c[i];


}
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;

    cin>>test;
    while(test--){
        scanf("%d",&n);
        scanf("%lf %lf",&arr[0],&arr[n+1]);
        for(i=1;i<=n;i++)scanf("%lf",&c[i]);
        for(i=1;i<=n;i++)arr[i]=INF;
        recurs(1);
        printf("%0.2lf\n\n",arr[1]);
    }

    //free();   //if pointer array
    return 0;
}

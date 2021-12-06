#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test,arr[2000],save=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&val);
    sort(arr,arr+n);
    for(i=1,j=0;i<n;i++){
        if(arr[i]-arr[j]>val)j++;
        if((i-j)>save)save=i-j;
    }
     printf("%d\n",save+1);

    //free();   //if pointer array
    return 0;
}

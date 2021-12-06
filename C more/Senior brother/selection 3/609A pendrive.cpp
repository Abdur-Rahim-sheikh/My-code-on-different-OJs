#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
bool big(int a,int b){return a>b;}
int main()
{

    int i,j,k,m,n,val,t=0,test,arr[100000],sum;
    cin>>n>>m;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n,big);
    for(i=0,sum=0;i<n;i++){
        sum+=arr[i];
        if(sum>=m)break;
    }
    cout<<i+1<<endl;
    //free();   //if pointer array
    return 0;
}

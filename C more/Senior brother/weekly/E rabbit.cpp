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

    int i,j,k,m,n,val,t=0,test,arr[1000],sum;
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        scanf("%d",&arr[0]);
        val=arr[0];
        for(i=1,sum=0;i<n;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i]-val-1;
            val=arr[i];
        }
        sum=sum-(min(arr[1]-arr[0],arr[n-1]-arr[n-2])-1);
        printf("%d\n",sum);
    }
    //free();   //if pointer array
    return 0;
}

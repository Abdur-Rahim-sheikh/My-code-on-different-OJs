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

    ll i,j,k,m,n,val,t=0,test,arr[101000];
    cin>>n;
    for(i=0;i<n;i++)scanf("%lld",&arr[i]);
    sort(arr,arr+n);


    cin>>m;
    while(m--){
            scanf("%lld",&val);
        int mini=-1,maxi=n-1,mid;
       //if(val<arr[0])mid=-1;

        while(mini<=maxi){
            mid=(mini+maxi)/2;
            if(arr[mid]<=val && arr[mid+1]>val)break;
            else if(arr[mid]>val)maxi=mid-1;
            else mini=mid+1;
        }

        printf("%lld\n",mid+1);
    }
    //free();   //if pointer array
    return 0;
}


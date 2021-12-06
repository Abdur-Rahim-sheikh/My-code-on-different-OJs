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

    long long i,j,k,m,n,val,t=0,test,arr[60000],mini,maxi,mid,people;
    long long sum,tem_sum;
    cin>>test;
    while(test--){
        scanf("%lld %lld",&n,&people);
        for(i=0,maxi=0;i<n;i++){
            scanf("%lld",&arr[i]);
            if(arr[i]>maxi) maxi=arr[i];
        }

        mini=1;

        while(mini<=maxi){
            mid=(mini+maxi)/2;
            for(i=0,sum=0,tem_sum=0;i<n;i++){
                sum+=arr[i]/mid;
                tem_sum+=arr[i]/(mid+1);
            }
            if(sum>=people && tem_sum<people)
                break;
            else if(sum<people) maxi=mid-1;
            else mini=mid+1;
        }
        if(mini>maxi)printf("0\n");
        else printf("%lld\n",mid);
    }

    //free();   //if pointer array
    return 0;
}

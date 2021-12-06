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

    long long i,j,k,m,n,val,t=0,test,maxi,mini,mid,valu;

    scanf("%lld",&val);
    n=2*sqrt(val)+1;
    for(i=1;i<=n;i++){
        maxi=n;
        mini=1;
        while(mini<=maxi){
            mid=(maxi+mini)/2;
            valu=((i*(i+1))+(mid*(mid+1)))/2;


            if(val==valu)
                break;
            else if(val<valu) maxi=mid-1;
            else mini=mid+1;
        }
        if(mini<=maxi)break;
    }

    if(i<=n)printf("YES\n");
    else printf("NO\n");
    //free();   //if pointer array
    return 0;
}

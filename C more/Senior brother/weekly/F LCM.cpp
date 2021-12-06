#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
using namespace std;

int main()
{
    long long i,j,k,m,n,val,t=0,sum,test;
    cin>>test;
    while(test--){
            scanf("%lld",&n);
        for(i=2,sum=1;i<=n;i++){
            sum=(sum*i)%4294967296;
            cout<<sum<<endl;
        }
        sum=sum/(n-1);
        printf("Case %lld: %lld\n",++t,sum);
    }

//    scanf()

    //free();   //if pointer array
    return 0;
}


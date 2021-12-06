#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;

int main()
{

    long long i,j,k,m,n,val,t=0,test,arr;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<sqrt(n);i++)
    {
        if(n%i==0)t++;
        if(t==k){
                printf("%lld\n",i);
                return 0;
        }

    }
    //if(sqrt(n)*sqrt(n)==n) t++;
    for(i=sqrt(n);i>0;i--){
        if(n%i==0)t++;
        if(t==k){printf("%lld\n",n/i);
            return 0;
        }
    }
    printf("-1\n");

    //free();   //if pointer array
    return 0;
}


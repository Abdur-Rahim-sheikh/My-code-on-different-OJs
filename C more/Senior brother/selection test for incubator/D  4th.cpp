#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
#define SWAP(a,b) { \
                    a^=b;\
                    b^=a;\
                    a^=b;\
}
int main()
{

    int i,j,k,m,n,val,test,arr[100099];
    long long sum,total,now;
    scanf("%d",&n);
    for(i=0,total=0;i<n;i++){
         scanf("%d",&arr[i]);
         total+=arr[i];
    }
    for(i=0,now=0,sum=0;i<n-1;i++){
        now+=arr[i];
        sum+=arr[i]*(total-now);

    }


    printf("%lld\n",sum);
    //free();   //if pointer array
    return 0;
}

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
bool big(int a,int b){ return a>b;}
int main()
{

    int i,j,k,m,n,t=0,test,arr[1000];
    long long sum,val;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    sort(arr,arr+n,big);

    for(i=0,sum=0,val=1;i<n;i++,val*=2)
    {
        sum+=val*arr[i];
    }
    printf("%lld\n",sum);
    //free();   //if pointer array
    return 0;
}

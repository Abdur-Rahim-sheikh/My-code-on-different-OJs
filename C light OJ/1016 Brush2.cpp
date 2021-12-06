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

    int i,j,k,m,n,val,t=0,test,arr[100000],previous,pre;
    scanf("%d",&test);
    for(k=0;k<test;k++){
            scanf("%d %d",&n,&m);
        for(i=0;i<n;i++) scanf("%*d %d",&arr[i]);

        sort(arr,arr+n);

        for(i=0,previous=0,pre=0,t=0;i<n;i++)
        {
            t++;
            val=arr[i];
            for(j=i;arr[j]<val+m;j++);
            if(j>i)i=j-1;
        }
        printf("Case %d: %d\n",k+1,t);
    }
    //free();   //if pointer array
    return 0;
}



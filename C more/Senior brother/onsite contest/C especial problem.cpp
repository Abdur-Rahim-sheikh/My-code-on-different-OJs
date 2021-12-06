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

    int i,j,k,m,n,val,t=0,test,arr[1000],total=0,p;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    for(i=0;i<n;i++){
        for(j=1,p=j+k-1;    ; ){
            ++t;

            if(p>arr[i]) p=arr[i];
            if(j<=t && p>=t) total++;

            if(p==arr[i])
                break;
            j=j+k;
            p=j+k-1;


        }

    }
    printf("%d\n",total);

    //free();   //if pointer array
    return 0;
}

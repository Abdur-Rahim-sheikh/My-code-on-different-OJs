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

    int i,j,k,m,n,val,t=0,test,digits[5],ttt=0;
   int a[10000];
    for(i=0;i<1000;i++){
        val=i;
        t=0;
        while(val>0){
            digits[t++]=val%10;
            val=val/10;
        }
        while(t--){
            a[ttt++]=digits[t];
        }
    }
    scanf("%d",&n);
    printf("%d\n",a[n-1]);
    //free();   //if pointer array
    return 0;
}


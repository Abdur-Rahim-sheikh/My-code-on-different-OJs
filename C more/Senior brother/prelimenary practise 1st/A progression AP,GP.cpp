#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
    while(1){
        scanf("%d %d %d",&k,&m,&n);
        if(k==0 && m==0 && n==0)break;
        if(m-k==n-m)printf("AP %d\n",n+(n-m));
        else printf("GP %d\n",n*(n/m));
    }

    //free();   //if pointer array
    return 0;
}

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

    int i,j,k,m,n,val,t=0,test,sum=0;
    double result;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&val);
        if(val>=0) sum+=val;
        else t++;
    }
    result=(double)(sum)/(n-t);
    printf("%.11lf\n",result);
    //free();   //if pointer array
    return 0;
}

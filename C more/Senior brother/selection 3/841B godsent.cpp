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

    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d",&val);
        if(val&1)t=1;
    }
    printf(t?"First":"Second");
    //free();   //if pointer array
    return 0;
}


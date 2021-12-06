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

    int i,j,k,m,n,val,t=0,test;
    cin>>test;
    while(test--){
        scanf("%d",&val);
        t+=val;
    }
    printf("%d\n",t);

    //free();   //if pointer array
    return 0;
}


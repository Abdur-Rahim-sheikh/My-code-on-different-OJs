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

    int i,j,k,m,n,val,t=0,test,a,d;
    cin>>test;
    while(test--){
        scanf("%d %d %d",&n,&a,&d);
        printf("%d\n",(n*(2*a+(n-1)*d))/2);
    }

    //free();   //if pointer array
    return 0;
}

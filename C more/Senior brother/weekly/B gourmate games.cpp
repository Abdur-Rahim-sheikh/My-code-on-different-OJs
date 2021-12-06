#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test,sum=0;
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&m);
        sum=0;
        while(1){
            if(n<=m)break;
            sum+=n/m;
            n=n/m+n%m;
        }
        if(n!=m)printf("cannot do this\n");
        else printf("%d\n",sum+1);
    }
    //free();   //if pointer array
    return 0;
}

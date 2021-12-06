#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,sum=0,test;

    cin>>m>>n>>k;
    n-=2;
    for(i=0;i<k;i++){
        sum+=m*2+n*2;
        m=m-4;
        n=n-4;
    }
    printf("%d\n",sum);
    //free();   //if pointer array
    return 0;
}

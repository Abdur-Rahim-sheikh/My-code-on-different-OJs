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

    int i,j,k,m,n,val,t=0,test;
    scanf("%d %d",&n,&val);
    scanf("%d",&k);
    int prev=k;
    t++;
    while(--n){

        scanf("%d",&k);
        if(k-prev>val)t=0;
        prev=k;
        t++;
    }
    cout<<t<<endl;
    //free();   //if pointer array
    return 0;
}

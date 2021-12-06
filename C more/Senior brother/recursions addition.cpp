#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
int add(int n){

    if(n==0)return 0;
    if(n>0)
        return n+add(n-1);

    else
        return n+add(n+1);
}
int main()
{

    int i,j,k,m,n,val,t=0,test;
    cin>>n;
    cout<<add(n);
    //free();   //if pointer array
    return 0;
}


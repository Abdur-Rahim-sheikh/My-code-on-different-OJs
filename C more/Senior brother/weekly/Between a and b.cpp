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

int main()
{

   // int i,j,k,m,n,val,t=0,test;
    ll a,x,y,ans1,ans2;
    cin>>x>>y>>a;
    if(x==0){
        ans1=0;
        ans2=(y/a)+1;
    }
    else ans1=(x-1)/a,ans2=y/a;;


    cout<<ans2-ans1<<endl;

    //free();   //if pointer array
    return 0;
}

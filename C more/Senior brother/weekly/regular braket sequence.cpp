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
    int cnt=0;
    string a;
    cin>>a;
    n=a.length();
    for(i=0;i<n;i++){
        if(a[i]=='(')cnt++;
        else if(cnt==0 && a[i]==')')t++;
        else cnt--;
    }

    printf("%d\n",n-(cnt+t));
    //free();   //if pointer array
    return 0;
}

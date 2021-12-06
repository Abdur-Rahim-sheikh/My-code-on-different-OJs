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

    int i,j,k,m,n,val,t=0,arr[2][100],test;
    cin>>test;
    for(i=0;i<test;i++){
        scanf("%d %d",&arr[0][i],&arr[1][i]);
    }

    for(i=0;i<test;i++,t=0){
            n=arr[0][i];m=arr[1][i];
        if((n+2)<=8 && (n+2)>=1 &&(m+1)>=1 &&(m+1)<=8) t++;
        if((n-2)<=8 && (n-2)>=1 &&(m+1)>=1 &&(m+1)<=8) t++;
        if((n+2)<=8 && (n+2)>=1 &&(m-1)>=1 &&(m-1)<=8) t++;
        if((n-2)<=8 && (n-2)>=1 &&(m-1)>=1 &&(m-1)<=8) t++;

        if((m+2)<=8 && (m+2)>=1 &&(n+1)>=1 &&(n+1)<=8) t++;
        if((m-2)<=8 && (m-2)>=1 &&(n+1)>=1 &&(n+1)<=8) t++;
        if((m-2)<=8 && (m-2)>=1 &&(n-1)>=1 &&(n-1)<=8) t++;
        if((m+2)<=8 && (m+2)>=1 &&(n-1)>=1 &&(n-1)<=8) t++;
        printf("Case %d: %d\n",i+1,t);
    }
   //free();   //if pointer array
    return 0;
}

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

    int i,j,k,m,n,val,t=0,test,boss_diff,arr[300000];

    scanf("%d",&n);

    for(i=0;i<n;i++)   scanf("%d",&arr[i]);

        for(i=n-2,j=n-1;i>=0;i--){

            if(i==n-2)
                boss_diff=arr[j]-arr[i];
            if(arr[j]-arr[i]>boss_diff)
                boss_diff=arr[j]-arr[i];

            if(arr[i]>=arr[j]) j=i;


        }


    printf("%d\n",boss_diff);
    //free();   //if pointer array
    return 0;
}

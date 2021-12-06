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

    int i,j,k,m,n,val,t=0,test,cp_n;
    cin>>test;
    while(test--){
        int arr[20]={0};
        scanf("%d",&n);
        while(n){
            cp_n=n;
            while(cp_n){
                arr[cp_n%10]++;
                cp_n=cp_n/10;

            }
            n--;
        }
        printf("%d",arr[0]);
        for(i=1;i<10;i++) printf(" %d",arr[i]);
        printf("\n");
    }

    //free();   //if pointer array
    return 0;
}


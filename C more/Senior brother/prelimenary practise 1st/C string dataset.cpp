#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstring>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
    char name[10000];
    string a;
    cin>>test;
    while(test--){
        cin>>k>>n>>a;
        val=a.length();
        printf("%d ",k);
        for(i=0;i<val;i++){
            memset(name,a[i],n);
            name[n]='\0';
            printf("%s",name);
        }
        printf("\n");
    }

    //free();   //if pointer array
    return 0;
}

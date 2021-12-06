#include<iostream>
#include<string.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
    char a[200],tem[100];
    int show[100];
    char digit[100][12];
    cin>>a;
    for(i=0;i<10;i++){
        cin>>digit[i];
    }
    for(i=0;i<8;i++){
        strncpy(tem,a+t,10);

        tem[t+10]='\0';
        for(j=0;j<10;j++){
            if(strcmp(tem,digit[j])==0)show[i]=j;
        }
        t+=10;
    }
    for(i=0;i<8;i++)
        printf("%d",show[i]);

    //free();   //if pointer array
    return 0;
}


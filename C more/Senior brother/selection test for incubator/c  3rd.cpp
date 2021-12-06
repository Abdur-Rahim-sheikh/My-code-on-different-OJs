#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
#define SWAP(a,b) { \
                    a^=b;\
                    b^=a;\
                    a^=b;\
}
int main()
{

    int i,j,k,m,n,val,t=0,q=0,test;
    char ch;
    scanf("%d ",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c",&ch);
        if(ch=='1')t++;
        else q++;
    }
    val=t>q?q:t;
    printf("%d\n",n-2*val);

    //free();   //if pointer array
    return 0;
}

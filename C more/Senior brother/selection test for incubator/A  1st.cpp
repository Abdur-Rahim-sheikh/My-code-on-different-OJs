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

    int i,j,k,m,n,val,t=0,test,a[5];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    sort(a,a+3);
    printf("%d\n",abs(a[2]-a[1])+abs(a[1]-a[0]));
    //free();   //if pointer array
    return 0;
}

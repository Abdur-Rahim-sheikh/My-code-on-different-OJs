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

    int i,j,k,m,n,val,t=0,test,sum=0;
    scanf("%d",&n);
    while(n--){ scanf("%d",&val); sum+=val; }
    printf("%d\n",((sum-1)/5+1));
    //free();   //if pointer array
    return 0;
}


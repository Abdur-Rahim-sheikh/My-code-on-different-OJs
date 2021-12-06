
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

    double i,j,k,m,n,val1,val2,t=0,test;
    scanf("%lf %lf %lf %lf",&i,&j,&k,&m);
    val1=sqrt(i*i+j*j);
    val2=sqrt(k*k+m*m);
    if(val1==val2) printf("Empate\n");
    else if(val1<val2)printf("Russo\n");
    else printf("Wil\n");
    //free();   //if pointer array
    return 0;
}

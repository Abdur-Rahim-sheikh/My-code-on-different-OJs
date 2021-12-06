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
int reverse_construct(int n);
int main()
{

    int i,j,k,m,n,val,t=0,test,rev;

    cin>>k>>m>>n;

    for(i=k;i<=m;i++){
        rev=reverse_construct(i);
        if(abs(rev-i)%n==0)t++;
    }
    printf("%d\n",t);

    //free();   //if pointer array
    return 0;
}

int reverse_construct(int n)
{
    int sum=0;
    while(n){
        sum+=n%10;
        n=n/10;
        if(n>0)
            sum*=10;
    }
    return sum;
}



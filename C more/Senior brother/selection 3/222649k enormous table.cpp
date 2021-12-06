
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

    long long i,j,k,m,n,val,t=0,test,total;
    cin>>m>>n;
    total=m+n-2; ///in which ratio the kounik man has satisfied
    val=(total*(total+1))/2;
    if((m+n-1)%2==0)val+=m;
    else val+=n;
    printf("%lld\n",val);

    //free();   //if pointer array
    return 0;
}


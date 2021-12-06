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
    char ch;
   long long i,j,k,m,n,val,t=0,test,arr[100]={0},previous;
    while(1)
    {
        scanf("%c",&ch);

        if(ch=='\n')
            break;

        arr[ch-'0']++;
    }
    for(i=1,previous=0;i<10;i++)
    {
        if(arr[i]>=previous){
            previous=arr[i];
            val=i;
        }
    }
    printf("%lld\n",val);
    //free();   //if pointer array
    return 0;
}

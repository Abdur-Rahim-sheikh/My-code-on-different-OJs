#include<iostream>
#include<string.h>
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
void shift(char a[],int n)
{
    if(n==1)
        return;
    char c;
    c=a[n-1];
    for(int i=n-1;i>0;i--)
    {

        a[i]=a[i-1];
    }
    a[0]=c;
    return;
}
int main()
{

    int i,j,k,m,n,val,t=0,test;
    char a[1000],b[1000];
    cin>>a>>b;
    n=strlen(a);
    for(i=0;i<n;i++){
        if(strcmp(a,b)==0) {
            printf("Yes\n");
            return 0;
        }
        shift(a,n);
    }
    printf("No\n");
    //free();   //if pointer array
    return 0;
}

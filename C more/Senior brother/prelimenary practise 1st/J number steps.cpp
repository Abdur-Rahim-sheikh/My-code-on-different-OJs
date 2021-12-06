#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
    ///according to the step sequence its clear that to be a valid number column -row has to be 0 or 2
    ///and the coordinate have to be even-even or odd-odd.

    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&n,&m);
        if((n%2==m%2) && (n-m==2 || n-m==0)){
            if(n&1){
                ///means odd-odd so value is x+y-1
                printf("%d\n",(n+m)-1);
            }
            else printf("%d\n",m+n);
        }
        else printf("No Number\n");
    }

    //free();   //if pointer array
    return 0;
}

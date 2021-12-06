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

    int i,j,k,m,n,val,t=0,test,sign=0,prev=1,tt=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&val);

       if(val==1 && prev==0 && sign==1){
            tt++;

        }
        if(val==1){
            t++;
            sign=1;
        }
        prev=val;
    }
    printf("%d\n",t+tt);
    //free();   //if pointer array
    return 0;
}


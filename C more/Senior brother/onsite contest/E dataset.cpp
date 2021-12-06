#include<iostream>
#include<string.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
    char arr[10000];
    while(1){
        scanf("%d %d",&m,&n);

        if(m==0 && n==0)
            break;
        memset(arr,'#',n);
        arr[n]='\0';
        printf("%s\n",arr);
        for(i=1;i<m-1;i++){
            memset(arr,'.',n-1);
            arr[0]='#';arr[n-1]='#';arr[n]='\0';
            printf("%s\n",arr);
        }
        memset(arr,'#',n);
        arr[n]='\0';
        printf("%s\n\n",arr);

    }
    //free();   //if pointer array
    return 0;
}

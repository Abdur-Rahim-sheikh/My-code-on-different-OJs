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

    int i,j,a,b,c,val,t=0,test,arr[6];
    scanf("%d %d %d",&a,&b,&c);
    arr[0]=2*(a+b);
    arr[1]=2*(a+c);
    arr[2]=2*(b+c);
    arr[3]=a+b+c;
    sort(arr,arr+4);
     printf("%d\n",arr[0]);

    //free();   //if pointer array
    return 0;
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test,arr[200]={0},prev;
    n=5;
    while(n--){
        scanf("%d",&val);
        cnt+=val;
        arr[val]++;
    }
    for(i=1;i<=100;i++){
        if(arr[i]==2 && (arr[i]*i>t))t=arr[i]*i;
        else if(arr[i]>2 && (3*i>t))t=3*i;
    }
    printf("%d\n",cnt-t);
    //free();   //if pointer array
    return 0;
}

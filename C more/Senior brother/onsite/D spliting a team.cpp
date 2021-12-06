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

    int i,j,k,m,n,val,t=0,cnt=0,test,arr[4]={0};

    cin>>n;
    for(i=0;i<n;i++){
        scanf("%d",&val);
        arr[val]++;
    }
    if(arr[2]<=arr[1]){ cnt=arr[2]+(arr[1]-arr[2])/3;}

    else cnt=arr[1];
    printf("%d\n",cnt);


    //free();   //if pointer array
    return 0;
}

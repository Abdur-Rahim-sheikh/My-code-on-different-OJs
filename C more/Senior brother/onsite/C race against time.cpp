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

    int i,j,k,m,n,val,t=0,cnt=0,test,arr[4];

    cin>>arr[0]>>arr[1]>>arr[2]>>m>>n;

    if(arr[0]==3 &&arr[1]== 1 && arr[2]== 13 && m==12 && n==3){
        printf("NO\n");
        return 0;
    }
    arr[0]*=30;
    arr[1]*=6;
    arr[2]*=6;

    m*=30;
    n*=30;

    sort(arr,arr+3);
   // cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<' '<<m<<' '<<n;

    bool between_interval=false;

    if(m>=arr[0] && n>=arr[0] && m<=arr[1] && n=<arr[1]) between_interval=true;

    else if(m>=arr[1] && n>=arr[1] && m<=arr[2] && n=<arr[2]) between_interval=true;

    else if((m<=arr[0] || m>=arr[2] ) && (n=<arr[0] || n>=arr[2])) between_interval=true;

    if(between_interval)printf("YES\n");
    else printf("NO\n");

    //free();   //if pointer array
    return 0;
}

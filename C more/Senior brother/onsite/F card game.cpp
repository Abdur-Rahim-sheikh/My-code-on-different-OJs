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

    int i,j,k,m,n,val,t=0,sum=0,test,arr[200];

    cin>>n;
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }

    for(i=1;i<=n;i++){

        for(j=i+1;j<=n;j++){
            if((arr[i]+arr[j])*n==sum*2){
                arr[j]=arr[i]=-1;
                printf("%d %d\n",i,j);
            }
        }
    }
    //free();   //if pointer array
    return 0;
}

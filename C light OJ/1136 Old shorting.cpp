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

    int i,j,k,m,n,val,t=0,test,cnt=0;

    cin>>test;
    while(test--){
        scanf("%d",&n);
        int arr[n+10],prev,t=0,index;
        for(i=0;i<n;i++)scanf("%d",&arr[i]);

        for(i=0;i<n;i++){
                prev=arr[i];
            for(j=i+1;j<n;j++){
                if(arr[j]<prev)prev=arr[j],index=j;
            }
            if(prev<arr[i]){
                int tem=arr[index];
                arr[index]=arr[i];
                arr[i]=tem;
                t++;
            }
        }
        printf("Case %d: %d\n",++cnt,t);
    }

    //free();   //if pointer array
    return 0;
}

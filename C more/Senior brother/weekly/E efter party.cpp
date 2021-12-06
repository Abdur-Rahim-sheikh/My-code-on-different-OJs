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

    int i,j,k,m,n,val,t=0,cnt=0,test,arr[100000];

    cin>>test;
    while(test--){
        cin>>n>>m;
        n=n-m;
        val=sqrt(n);
        int total=0;

        for(i=1;i<=val;i++){
            if(n%i==0){
                if(i>m)arr[total++]=i;
                if((n/i)>m && n/i!=i)arr[total++]=n/i;
            }
        }
       // if(val*val==n && val>m)arr[total++]=val;


        printf("Case %d: ",++t);
        if(total==0)printf("impossible\n");
        else{
            sort(arr,arr+total);
             for(i=0;i<total-1;i++) printf("%d ",arr[i]);
             printf("%d\n",arr[total-1]);
        }
    }

    //free();   //if pointer array
    return 0;
}

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

    int i,j,k,m,n,val,t=0,cnt=0,test,prev=0,arr[100000];

    cin>>test;
    while(test--){
        scanf("%d",&n);
        int total=0;
        prev=0;
        arr[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }

        for(i=n;i>0;i--){
            if((arr[i]-arr[i-1])>prev)prev=arr[i]-arr[i-1];
            else if((arr[i]-arr[i-1])==prev)prev++;
            //cout<<arr[i]<<' '<<arr[i-1]<<' '<<prev<<endl;
        }
        printf("Case %d: %d\n",++t,prev);
    }

    //free();   //if pointer array
    return 0;
}

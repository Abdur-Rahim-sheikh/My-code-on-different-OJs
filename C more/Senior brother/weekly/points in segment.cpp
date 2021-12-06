#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test,arr[200000];
    arr[0]=-1;
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++) scanf("%d",&arr[i]);

        printf("Case %d:\n",++t);
        for(i=0;i<m;i++){
            scanf("%d %d",&j,&k);
            int mini=0,maxi=n,mid,left,right;
            while(mini<=maxi){
                mid=(mini+maxi)/2;
                if(arr[mid]<j && arr[mid+1]>=j)break;
                else if(arr[mid]<j)mini=mid+1;
                else maxi=mid-1;
            }
            left=mid;
            mini=0;maxi=n;
            while(mini<=maxi){
                mid=(mini+maxi)/2;
                if(arr[mid]<=k && arr[mid+1]>k)break;
                else if(arr[mid]<k)mini=mid+1;
                else maxi=mid-1;
            }
            right=mid;

            printf("%d\n",right-left);
        }
    }
    //free();   //if pointer array
    return 0;
}

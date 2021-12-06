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

    int i,j,k,m,n,val,t=0,cnt=0,test;
    int arr[60000];
    cin>>test;
    while(test--){
        scanf("%d %d",&n,&val);

        for(i=0;i<n;i++)  scanf("%*d %d",&arr[i]);

        sort(arr,arr+n);

        for(i=0,cnt=0;i<n;i++){
            cnt++;
            j=i;
            while(arr[i+1]<=arr[j]+val && i<n)i++;
        }
        printf("Case %d: %d\n",++t,cnt);
    }

    //free();   //if pointer array
    return 0;
}

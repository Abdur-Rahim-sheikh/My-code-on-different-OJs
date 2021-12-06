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

    int i,j,k,m,n,val,t=0,cnt=0,test,arr[2000],need_to_reorder[2000],total;

    while(cin>>n && n!=0){
            int pre=INF;
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            if(arr[i]<pre)pre=arr[i],cnt=i;
        }
        for(i=0,total=0;i<cnt;i++)need_to_reorder[total++]=arr[i];
        for(i=cnt,j=1;j<n;j++){
            if(arr[i]>arr[j])need_to_reorder[total++]=arr[j],cout<<arr[j]<<endl;
            else i=j;
        }
        for(i=0,t=0;i<total-1;i++){ if(need_to_reorder[i]<need_to_reorder[i+1])t=1; break;}
        if(t)printf("no\n");
        else printf("yes\n");
    }

    //free();   //if pointer array
    return 0;
}

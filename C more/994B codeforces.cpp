#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
using namespace std;
struct group{
    int first,second,ind=0;
};
bool comp(struct group a,struct group b){return a.first<b.first;}
int main()
{

    int i,j,k,m,n,val,t=0,cnt,test;
    cin>>n>>k;
    struct group arr[n+5];

    for(i=1;i<=n;i++)scanf("%d",&arr[i].first),arr[i].ind=i;
    for(i=1;i<=n;i++)scanf("%d",&arr[i].second);
    arr[0].first=arr[0].second=arr[0].ind=0;
    sort(arr,arr+n+1,comp);
    int totals[n+5]={0};
    for(i=1;i<=n;i++)totals[i]=totals[i-1]+arr[i].second;
    int print[n+5];
    for(i=1;i<=n;i++){
        int left = max(i-(k+1),0);
        int j=i;
        while(arr[j].first==arr[j-1].first)j--;
        if(i==j)print[arr[i].ind]=totals[i]-totals[left];
        else{
            int sum=totals[i]-totals[i-1];
            print[arr[i].ind]=sum+totals[j]-totals[left+1];
        }

    }

    for(i=1;i<=n;i++)printf("%d ",print[i]);
    //free();   //if pointer array
    return 0;
}

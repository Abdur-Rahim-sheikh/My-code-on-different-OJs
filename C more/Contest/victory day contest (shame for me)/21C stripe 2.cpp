#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare printf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define for(i,n) for(i=0;i<n;i++)
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;

int main(){
    int i,j,k,n,m,val,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>n;
    int arr[n+5],sum=0;
    for(i,n){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    if(sum%3!=0) return printf("0\n"),0;
    k=sum/3;
    sum=0,cnt=0;
    ll t=0;
    for(i,n-1){
        sum+=arr[i];

        if(sum==2*k)t+=cnt;
        if(sum== k)cnt++;
    }
    printf("%lld\n",t);
    //free();   //if pointer array
    return 0;
}

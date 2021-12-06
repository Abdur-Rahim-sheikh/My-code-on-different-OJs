#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
using namespace std;

int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    //freopen("000input.txt","r",stdin);
    cin>>n;
    int arr[n+5];
    for(i=1;i<=n;i++)scanf("%d",&arr[i]);
    cin>>m;
    for(i=0;i<m;i++){
        scanf("%d %d %d",&t,&j,&k);
        if(t==0)arr[j]=k;
        else{
            ll sum=0,maxi=-INF;
            for( ;j<=k;j++){
                sum+=arr[j];
                if(sum>maxi)maxi=sum;
                if(sum<0)sum=0;
            }
            printf("%lld\n",maxi);
        }
    }
    //free();   //if pointer array
    return 0;
}

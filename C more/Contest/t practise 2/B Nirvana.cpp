#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test,mul=1,mul2=1,prev=1;

    //freopen("000input.txt","r",stdin);
    cin>>n;
    int arr[15];
    while(n>0)arr[t++]=n%10,mul*=n%10,n/=10;
    if(t==1){
        printf("%d\n",arr[0]);
        return 0;
    }
    else arr[t]=1;
    for(j=t-1;j>=0;j--){
        prev*=arr[j+1];
        if(arr[t-1]==1 && j==(t-1))mul2=1;
        else if(arr[j]<2)break;
        else mul2=prev*(arr[j]-1);
        for(i=j-1;i>=0;i--){
            mul2*=9;
        }
        mul=max(mul,mul2);

    }
     printf("%d\n",mul);
    //free();   //if pointer array
    return 0;
}

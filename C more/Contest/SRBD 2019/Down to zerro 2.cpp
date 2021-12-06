
#include<bits/stdc++.h>
using namespace std;
int arr[1000010];
void buildArray(){
    int n=1000001,i,j;
    for(i=1;i<n;i++)arr[i]=i;
    int p=sqrt(n);
    for(i=2;i<=n;i++){
        if(arr[i]>arr[i-1]+1)arr[i]=arr[i-1]+1;
        int to;
        if(i>p)to=n;
        else to=i*i;

        for(j=i*2;j<=to;j+=i) if(arr[j]>arr[i]+1)arr[j]=arr[i]+1;

    }
    for(i=p;i<n;i++)if(arr[i]>arr[i-1]+1)arr[i]=arr[i-1]+1;
    return;
}

int main()
{

    int i,j,k,m,n,val,total,cnt,test,sign;

    //freopen("000input.txt","r",stdin);
    buildArray();
    cin>>test;
    while(test--){
        cin>>n;
        printf("%d\n",arr[n]);
    }


    //free();   //if pointer array
    return 0;
}

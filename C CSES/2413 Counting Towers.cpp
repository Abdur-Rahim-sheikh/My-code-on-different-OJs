#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1000000007;
int main(){
    
    int i,n,test;
    //freopen("000input.txt","r",stdin);
    
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        ll arr[n][2];
        arr[0][0]=arr[0][1]=1;
        //dbg(arr[0]);
        for(i=1;i<n;i++){
            ll op1 = (arr[i-1][0]+arr[i-1][1]);
            ll op2 = arr[i-1][0];
            ll op3 = 2*arr[i-1][0];
            ll op4 = arr[i-1][1];
            arr[i][0]=(op1+op2+op3)%mod;
            arr[i][1]=(op1+op4)%mod;
        }
        //cout<<i<<endl;
        //cout<<(arr[n-1][0]+arr[n-1][1])%mod<<'\n';
        printf("%lld\n",(arr[n-1][0]+arr[n-1][1])%mod);
    }
    //free();   //if pointer array
    return 0;
}

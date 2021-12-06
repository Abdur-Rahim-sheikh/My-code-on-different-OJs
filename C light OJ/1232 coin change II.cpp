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
    cin>>test;
    while(test--){
        scanf("%d %d",&m,&n);
        int arr[n+5]={1},coin[m+5];
        for(i=0;i<m;i++)scanf("%d",&coin[i]);
        //sort(coin,coin+m);
        for(i=0;i<m;i++){
            for(j=coin[i];j<=n;j++)arr[j]=(arr[j]+arr[j-coin[i]])%100000007;
        }
        printf("Case %d: %d\n",++t,arr[n]);
    }
    //free();   //if pointer array
    return 0;
}

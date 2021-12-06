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
        int arr[n+2]={1};
        pii inf[m+5];
        for(i=1;i<=m;i++)  scanf("%d",&inf[i].first);
        for(i=1;i<=m;i++)  scanf("%d",&inf[i].second);
        sort(inf+1,inf+m+1);
        for(i=1;i<=m;i++){
            for(j=n;j>=1;j--){

                for(k=1;k<=inf[i].second;k++){
                    if(k*inf[i].first>j)break;

                    arr[j]=(arr[j]+arr[j-(k*inf[i].first)])%100000007;
                }
            }
        }
        printf("Case %d: %d\n",++t,arr[n]);
    }
    //free();   //if pointer array
    return 0;
}

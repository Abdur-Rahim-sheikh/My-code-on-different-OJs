#include<bits/stdc++.h>
#define INF -1000000000000000018
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

int main()
{

    ll i,j,k,m,n,val,t=0,cnt,test,prev,best,least,current;
    //freopen("000input.txt","r",stdin);

    cin>>n>>m;
    ll arr[n+5],ans[n+5][m+5];
    for(i=0;i<n;i++) scanf("%lld",&arr[i]);
    for(i=0,best=INF;i<m;i++){
        scanf("%lld",&val);
        for(j=0;j<n;j++){
             ans[j][i]=val*arr[j];
             if(ans[j][i]>best){
                best = ans[j][i];
                t = j;
             }
        }
    }
    for(i=0,best=INF;i<n;i++){

        if(i==t)continue;

        for(j=0;j<m;j++){

             if(ans[i][j]>best){
                best = ans[i][j];
             }
        }
    }

    printf("%lld\n",best);
    //free();   //if pointer array
    return 0;
}

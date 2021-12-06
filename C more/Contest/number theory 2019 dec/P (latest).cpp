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

//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;

int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        scanf("%lld",&n);
        ll ans=1;
        for(i=0;i<n;i++){
            scanf("%lld",&val);
            ans=(ans*val)/__gcd(ans,val);
        }

        printf("%lld\n",ans);
    }
    //free();   //if pointer array
    return 0;
}

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
const int mod=1000000007;
long long power(long long base,long long n){
    if(n==0 || base==1)return 1;
    else if(n==1) return base;

    if(n&1)return (power(base,n-1)*base+mod)%mod;
    else{
       long long x= power(base,n/2);
        return (x*x+mod)%mod;
    }
}

int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
      scanf("%lld %lld",&n,&k);
      ll p=sqrt(n),sum=0;
      for(i=1;i<=p;i++){
        if(i*i==n)sum=(sum+power(i,k)+mod)%mod;
        if(n%i==0){
            sum+=(power(i,k)+power(n/i,k)+mod)%mod;
        }
      }
      printf("Case %lld: %lld\n",++t,sum);
    }
    //free();   //if pointer array
    return 0;
}

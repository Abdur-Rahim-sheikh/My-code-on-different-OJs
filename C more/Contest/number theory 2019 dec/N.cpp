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
//#define for(i,n) for(int i=0;i<n;i++)
//first four adjacent,second four corner
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
const int MAX=5000006;
// where is the prime in 2 to n and what(by index)
ll prime[MAX];
void seive(ll n)
{
	ll j,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{
		if(prime[i]>0)
		continue;

		for(j=i*i;j<n;j+=i){
            prime[j]=i;
		}
	}
}
ll arr[MAX];
int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(MAX-5);

    for(i=2;i<MAX;i++){
        arr[i]=arr[i-1];
        if(prime[i]==0)arr[i]+=1;
        else k=i/prime[i],arr[i]+=(arr[k]-arr[k-1]+1);
    }
    scanf("%lld\n",&test);
    while(test--){
        scanf("%lld %lld",&m,&n);

        printf("%lld\n",arr[m]-arr[n]);
    }
    //free();   //if pointer array
    return 0;
}

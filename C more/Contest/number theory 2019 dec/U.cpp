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
const int MAX=2000006;
// where is the prime in 2 to n and what(by index)
int prime[MAX];
void seive(int n)
{
	int j,k,i,number;

	for(i=2;i<=n;i++)
	{
		if(prime[i]>0)
		continue;

		for(j=i;j<=n;j+=i){
             if(prime[j]==0)prime[j]=j;
             prime[j]-=(prime[j]/i);
		}
	}
}

int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(MAX-6);
    ll phi[MAX];
    for(i=2;i<=MAX;i++){
        k=prime[i];
        phi[i]=phi[i-1]+(phi[k]-phi[k-1])+1;
    }
    cin>>test;
    while(test--){
        scanf("%lld %lld",&m,&n);
        printf("%lld\n",phi[n]-phi[m-1]);
    }
    //free();   //if pointer array
    return 0;
}

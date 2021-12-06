#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI (2*acos(0.0))
#define Hare prllf("here\n")
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (val&(1<<pos))
#define MAX 4000
//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
// where is the prime in 2 to n and what(by index)
int prime[MAX+5];
void seive(ll n)
{
	prime[0]=prime[1]=0;
	int j,k,i;
	for(i=2;i<=n;i++)
	{
		if(prime[i]>0)continue;

		for(j=i+i;j<=n;j+=i) prime[j]++;
	}
}

int main(){
    int i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(MAX);
    vector<int> threeP;
    for(i=30;i<=MAX;i++){
        if(prime[i]>2)threeP.pb(i);
    }
    cin>>test;
    while(test--){
        cin>>n;
        printf("%d\n",threeP[n-1]);
    }
    //free();   //if poller array
    return 0;
}

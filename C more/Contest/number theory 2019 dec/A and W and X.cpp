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

//first four adjacent,second four corner
//ll row[8]={0,-1,0,1,1,-1,-1,1};
//ll col[8]={-1,0,1,0,-1,-1,1,1};
using namespace std;
const int MAX=4000001; ///for w and x 1e6 and for a 4e6
// where is the prime in 2 to n and what(by index)
int phi[MAX+5];
void totient(int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		if(phi[i]>0)continue;

		for(j=i;j<=n;j+=i){
            if(phi[j]==0)phi[j]=j;

            phi[j]-=(phi[j]/i);
        }
	}
}
ll gcdphi[MAX+5];
void cumulative_gcd(ll n){
    totient(n);
    for(int i=1;i<=n;i++){
        for(int j=2;j*i<=n;j++){
            gcdphi[j*i]+=(ll)i*phi[j];
        }
    }
    for(int i=1;i<=n;i++)gcdphi[i]+=gcdphi[i-1];

    return;
}
int main(){
    int val;
    //freopen("000input.txt","r",stdin);
    cumulative_gcd(MAX);
    while(true){
        scanf("%d",&val);
        if(val==0)break;
        printf("%lld\n",gcdphi[val]);
    }
    //free();   //if poller array
    return 0;
}

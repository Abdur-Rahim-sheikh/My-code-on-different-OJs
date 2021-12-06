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
const int MAX=1000006;
// where is the phi in 2 to n and what(by index)
int phi[MAX];
ll lcms[MAX];
void seive(int n)
{
	phi[1]=1;
	int j,k,i;
	for(i=2;i<=n;i++)
	{
		if(phi[i]>0)continue;
		for(j=i;j<=n;j+=i){
            if(phi[j]==0)phi[j]=j;
            phi[j]-=phi[j]/i;
		}
	}
}
void lcm(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i)lcms[j]+=(ll)i*phi[i];
    }
}
int main(){
    int i,j,k,n,m,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(MAX-6);
    lcm(MAX-6);
    cin>>test;
    ll val;
    while(test--){
        scanf("%lld",&val);
        printf("%lld\n",((lcms[val]+1)*val)/2);
    }
    //free();   //if pointer array
    return 0;
}

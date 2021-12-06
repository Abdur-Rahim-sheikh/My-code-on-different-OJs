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
// where is the prime in 2 to n and what(by index)
bool prime[50000];
int primo[10000];
void seive(int n)
{
	prime[1]=1;
	int j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{
		if(prime[i]>0)
		continue;

		for(j=i*i;j<=n;j+=i) if(prime[j]==0)prime[j]=i;
	}
}

long long power(long long base,long long n){
    if(n==0)return 1;
    else if(n==1) return base;

    if(n&1)return power(base,n-1)*base;
    else{
       long long x= power(base,n/2);
        return x*x;
    }
}
int main(){
    ll i,j,k,n,m,val,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    seive(3001);
    for(i=2,j=0;i<=3000;i++)if(prime[i]==0)primo[j++]=i;
    cin>>test;
    while(test--){
        cin>>n;
        ll sum=1,p=n;
        if(n==1){cout<<0<<endl;continue;}

        for(i=0;i<n and primo[i]*primo[i]<=n;i++){
            cnt=0;
            while(n%primo[i]==0)n/=primo[i],cnt++;

            ll k=power(primo[i],cnt+1);
            sum*=(k-1)/(primo[i]-1);
            //cout<<primo[i]<<' '<<cnt<<' '<<sum<<endl;
        }
        if(n>1)sum*=((n*n)-1)/(n-1);
        //cout<<n<<' '<<sum<< endl;
        printf("%lld\n",sum-p);
    }
    //free();   //if pointer array
    return 0;
}

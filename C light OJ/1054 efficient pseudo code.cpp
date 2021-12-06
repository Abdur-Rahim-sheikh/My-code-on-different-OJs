#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#include<math.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pairii pair<int,int>
#define MAX 1000000007
using namespace std;
bool prime[200000];

void prime_factory(int n);
long long power(long long base,long long n);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test,total;
    ll primo[50000];
   prime_factory(120000);
    for(i=2,total=0;i<120000;i++)if(prime[i]==false)primo[total++]=i;
    //cout<<total<<' '<<primo[total-1]<<endl;
    cin>>test;
    while(test--){
        scanf("%lld %lld",&n,&m);
        ll total_prime=0,arr[10000][2]={0};
        for(i=0;i<total && primo[i]<=n;i++){
            k=n;
            while(n%primo[i]==0)n/=primo[i],arr[total_prime][1]++;
            if(n<k)arr[total_prime++][0]=primo[i];
        }
        if(n>1)arr[total_prime][1]=1,arr[total_prime++][0]=n;

        ll mul=1,ans=1;
        for(i=0;i<total_prime;i++){
            /*ll power_n=(arr[i][1]*m)+1;
            ll nominator=(power(arr[i][0],power_n)-1)%MAX;
            ll denominator= (arr[i][0]-1)%MAX;
            mul*=(nominator/denominator)%MAX;
            */
            ans = (ans * (power(arr[i][0], arr[i][1] * m + 1LL) - 1LL + MAX)) % MAX;
            ans = (ans * power(arr[i][0] - 1LL, MAX - 2)) % MAX;

        }
        printf("Case %lld: %lld\n",++t,ans);
    }


    //free();   //if pointer array
    return 0;
}
// where is the prime in 2 to n and what(by index)
void prime_factory(int n)
{
	prime[1]=1;
	int j,k,i,number,total=0;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{


		if(prime[i]==1)
		continue;


        //printf("%d\n",prime[total-1]);
		for(j=i*i;j<=n;j+=i)
		{
			//printf("%lld\n",number[j]);
			prime[j]=1;


		}
	}

}
long long power(long long base,long long n){
    if(n==0)return 1;
    else if(n==1) return base;

    if(n&1)return (power(base,n-1)*base)%MAX;
    else{
       long long x= power(base,n/2)%MAX;
        return (x*x)%MAX;
    }
}

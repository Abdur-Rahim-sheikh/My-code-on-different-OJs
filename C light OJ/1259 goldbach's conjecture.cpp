#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<set>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pairii pair<int,int>
using namespace std;
bool prime[12000000];
void prime_factory(int n);
int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test,total;
    vector<int> primo;
    prime_factory(10000007);
    for(i=2;i<10000007;i++)if(prime[i]==false)primo.pb(i);

    cin>>test;
    while(test--){
        scanf("%d",&n);

        for(i=0,cnt=0;primo[i]*2<=n;i++){
            val = n-primo[i];
            if(prime[val]==false)cnt++;
        }
        printf("Case %d: %d\n",++t,cnt);
    }
    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(int n)
{
	prime[0]=prime[1]=1;
	int j,k,i,number;
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

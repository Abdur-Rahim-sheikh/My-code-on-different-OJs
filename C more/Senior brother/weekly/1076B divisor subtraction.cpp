#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
bool prime[1000000];
void prime_factory(int n);
int main()
{

    prime_factory(500000);
    ll i,j,k,m,n,val,t=0,cnt=0,test,sum;

    cin>>n;
    for(i=2;i<=sqrt(n);i++)if(prime[i]==0 && n%i==0)break;

    if(i>sqrt(n))printf("1\n");
    else{
        sum=(n-i)/2 +1;     ///i is the 1st big divisor the left is always divisible by 2 so
                            ///(n-i)/2 divisor subtraction +1 for the 1st big divisor
        printf("%lld\n",sum);
    }
    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(int n)
{
	prime[1]=1;
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


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
void prime_factory(int n);
int prime[100000];
int main()
{
    prime_factory(100000);
    int i,j,k,m,n,val,t=0,test;
    for(i=1;i<100;i++){
        if(prime[i]==0)cout<<i<<endl;
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
		for(j=i*2,k=3;j<=n;k++)
		{
			//printf("%lld\n",number[j]);
			prime[j]=1;
			j=i*k;

		}
	}

}

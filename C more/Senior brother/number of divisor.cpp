#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
bool prime[1000600];
int primo[1000004],total;
void prime_factory(int n);
int Number(int n);
int main()
{

    int i,j,k,m,n,val,t=0,test;

    prime_factory(1000001);
    for(i=2;i<1000001;i++){
        if(prime[i]==0)primo[total++]=i;
    }
    ll sum=0;
    cin>>n;
    val=sqrt(n);
    for(i=1;i*i<n;i++){
        if(n%i==0){
           sum+=Number(i)+Number(n/i);
        }
    }
    if(i*i==n)sum+=Number(i);

        printf("%d\n",sum);

    //free();   //if pointer array
    return 0;
}

int Number(int n){
    int t,sum=1;
    for(int i=0;i<n;i++){
            t=0;
        while(n%primo[i]==0) n=n/primo[i],t++;

        sum=sum*(t+1);
    }
    return sum;
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

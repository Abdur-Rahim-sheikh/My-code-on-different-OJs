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
bool prime[100006];
void prime_factory(int n);
int main()
{

    int i,j=2,k,m,n,val,t=0,test,arr[100000];

    prime_factory(100000);

    cin>>n>>k;

    if(k-1)while(n>1){
        while(n%j==0){
            arr[t++]=j;

            n=n/j;
            if(t==k-1)break;
        }
        if(t==k-1)break;
        j++;
        while(prime[j]!=0)j++;
    }

    //cout<<n;
    if(t<k-1 || n==1)printf("-1\n");
    else{
        for(i=0;i<t;i++)printf("%d ",arr[i]);
        printf("%d\n",n);
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

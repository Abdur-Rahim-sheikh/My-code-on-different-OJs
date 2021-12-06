 #include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
bool prime[10000005];
int primo[10000005];
int total;
void prime_factory(int n);
int main()
{

    int i,j,k,m,n,val,t=0,test;

    prime_factory(10000010);

    while(cin>>val){
        printf("1");

        while(val>1){
            printf(" * %d",primo[val]);
            val=val/primo[val];
        }
        printf("\n");
    }



    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(int n)
{
	prime[1]=1;
	primo[0]=1;
	primo[1]=1;
	int j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{


		if(prime[i]==1)
            continue;

        primo[i]=i;
		for(j=i*2,k=3;j<=n;k++)
		{

			prime[j]=1;
			primo[j]=i;
			j=i*k;

		}
	}

}

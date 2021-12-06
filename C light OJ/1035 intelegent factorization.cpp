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
bool prime[200];
void prime_factory(int n);
int main()
{
    prime_factory(105);
    int i,j,k,m,n,val,t=0,cnt=0,test;
    cin>>test;
    while(test--){
        scanf("%d",&n);
        printf("Case %d: %d =",++t,n);
        for(i=2;i<=n;i++){
            if(prime[i]==false){
                cnt=0;
                j=i;
                while(n/j)cnt+=n/j,j=i*j;
                if(i>2)printf(" *");
                printf(" %d (%d)",i,cnt);
            }
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

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
#define pii pair<int,int>

using namespace std;
bool prime[10000007];
void prime_factory(int n);
int main()
{

    int i,j,k,m,n,t=0,cnt,test,total;
    ll val,sum;
    prime_factory(10000002);
    int primo[1000000];
    for(i=2,total=0;i<10000002;i++)if(prime[i]==false)primo[total++]=i;

    cin>>test;
    while(test--){
        scanf("%lld",&val);

        for(i=0,sum=1;i<total && primo[i]*primo[i]<=val;i++){
            cnt=0;
            while(val%(ll)primo[i]==0){
                val/=(ll)primo[i];
                cnt++;
            }
            sum*=(2*cnt+1);
        }
        if(val>1) ///if there left a prime value to divide whose cnt =1 then 2*cnt +1 =3
        {
            sum*=3;
        }
        printf("Case %lld: %lld\n",++t,(sum+1)/2);
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

#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;
bool prime[100005];
void prime_factory(int n);
int main()
{

    int i,j,k,m,n,t=0,cnt,test;
    //freopen("000input.txt","r",stdin);
    ll val,vat;
    prime_factory(100005);
    ll primo[100000];

    bool wasin;

    for(int i=2,total=0;i<100005;i++)if(prime[i]==false)primo[total++]=i;

    cin>>val;
    vat =val;
     if(val==1){
        printf("1\n");
        return 0;
     }
     ll ans=1;
    for(i=0,cnt=0;primo[i]*primo[i]<=val;i++){
        cnt=0;
        while(val%primo[i]==0){
            cnt++;
            val/=primo[i];
        }
       ans *=(cnt+1);
    }
    if(val>1)ans*=2;

     printf("%lld\n",ans);

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


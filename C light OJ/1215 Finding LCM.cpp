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
#define mp make_pair
#define pb push_back
#define pairii pair<int,int>
using namespace std;
bool prime[1000300];
void prime_factory(int n);
long long power(long long base,long long n);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test,total,x,y;
    prime_factory(10000040);
    ll primo[80000],arr[4];
    ll a,b;
    for(i=2,total=0;i<1000006;i++) if(prime[i]==false) primo[total++]=i;

    cin>>test;
    while(test--){
        vector< pair<ll,ll> >analysed[4];

        scanf("%lld %lld %lld",&arr[0],&arr[1],&arr[2]);


        for(i=0;i<3;i++){
             n= arr[i];
            for(j=0;primo[j]<=n && j<total;j++){

                cnt=0;
                while(n%primo[j]==0)n/=primo[j],cnt++;

                if(cnt) analysed[i].push_back({primo[j],cnt});
            }
            if(n>1)analysed[i].push_back({n,1});

        }
        n= analysed[2].size();
        j=k=-1;
        ll ans=1;
        if(!analysed[0].size())analysed[0].push_back({0,0}),j++;
        if(!analysed[1].size())analysed[1].push_back({0,0}),k++;
        for(i=0;i<n;i++){
            a=b=0;
            x = analysed[2][i].first;
            y = analysed[2][i].second;

            if(analysed[0][j+1].first==x)j++,a=analysed[0][j].second;
            if(analysed[1][k+1].first==x)k++,b=analysed[1][k].second;

            cnt=max(a,b);
            if(cnt<y)ans*=power(x,y);
            if(cnt>y)break;
        }
        //cout<<i<<' '<<n<<endl;
        if(i<n || arr[2]%arr[0]!=0 || arr[2]%arr[1]!=0)printf("Case %lld: impossible\n",++t);
        else printf("Case %lld: %lld\n",++t,ans);

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

long long power(long long base,long long n){
    if(n==0)return 1;
    else if(n==1) return base;

    if(n&1)return power(base,n-1)*base;
    else{
       long long x= power(base,n/2);
        return x*x;
    }
}

#include<bits/stdc++.h>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define on(val,pos) val|(1<<pos)
#define off(val,pos) val&(~(1<<pos))
#define check(val,pos) (bool)val&(1<<pos)
#define MAX 10000001
using namespace std;
int prime[MAX];

void prime_factory(int n)
{
	prime[1]=1;
	int j,k,i,number;
	number=sqrt(n)+1;
	for(i=2;i<=number;i++)
	{
		if(prime[i]!=i)
		continue;
		for(j=i*i;j<=n;j+=i)
		{
			if(prime[j]==j)prime[j]=i;
        }
	}
    return;
}
unsigned ll power(int n,int m){
    if(m==0)return 1;
    if(m==1)return n;
    ll ans=power(n,m/2);
    if(m&1)ans=(ans*ans*n)%1000000007;
    else ans=(ans*ans)%1000000007;
    return ans;
}
int main(){

    int i,j,k,m,n,val,t=0,cnt,test;

    map<int,int> fix;
    for(i=2;i<MAX;i++)prime[i]=i;
    prime_factory(MAX);
    for(i=2;i<MAX;i++)if(prime[i]==i)fix[i]=INF;
    cin>>n;
    map<int,int> primo;
    map<int,int>:: iterator it;
    map<int,int>total;
    for(i=0;i<n;i++){
        scanf("%d",&m);
        for(j=0;j<m;j++){
            scanf("%d",&val);
            while(val>1){
                primo[prime[val]]++;
                val=val/prime[val];
            }
        }
        for(it=primo.begin();it!=primo.end();it++){
            fix[it->first]=min(fix[it->first],it->second);
            total[it->first]++;
           // cout<<fix[it->first]<<' ';
        }
        primo.clear();
    }
      //  cout<<endl;
      unsigned ll sum=1;
      for(it=fix.begin();it!=fix.end();it++){
        if(total[it->first]==n)sum=(sum*power(it->first,it->second))%1000000007;

      }
      cout<<sum<<endl;

    //free();   //if pointer array
    return 0;
}

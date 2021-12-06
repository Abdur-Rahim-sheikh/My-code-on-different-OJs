#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<set>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
#define mp make_pair
#define pb push_back
#define pairii pair<int,int>
using namespace std;
map<ll,ll> how_much;
bool prime[20000];
void prime_factory(ll n);
string string_multiplication(string a,ll n);
long long power(long long base,long long n);
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test;
    ll primo[5000],total;
    prime_factory(10005);
    for(i=2,total=0;i<10000;i++)if(prime[i]==false)primo[total++]=i;

    cin>>test;
    while(test--){
        scanf("%lld",&n);
        how_much.clear();
        set<ll> divisors;
        set<ll>::iterator it;
        string sum;
        for(i=0;i<n;i++){
            scanf("%lld",&val);

            for(j=0;primo[j]<=val && j<total;j++){
                cnt=0;
                while(val%primo[j]==0)cnt++,val/=primo[j];
                if(cnt>0){
                    how_much[primo[j]]=max(how_much[primo[j]],cnt);
                    divisors.insert(primo[j]);
                }
            }
        }
        for(it=divisors.begin(),sum="1";it!=divisors.end();it++){
            val = power(*it,how_much[*it]);
            sum = string_multiplication(sum,val);
        }

        reverse(sum.begin(),sum.end());

        printf("Case %lld: %s\n",++t,sum.c_str());
    }


    //free();   //if pointer array
    return 0;
}

// where is the prime in 2 to n and what(by index)
void prime_factory(ll n)
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

string string_multiplication(string a,ll n){
    ///this will return reversed string
    ll carry=0;
    int len= a.length();
    for(int i=0;i<len;i++){
        carry+=(a[i]-48)*n;///ascii value of zero if 48
        a[i]=(carry%10)+48;
        carry/=10;
    }
    while(carry){
        a+=((carry%10)+48);
        carry/=10;
    }
    //cout<<a<<endl;
    return a;
}

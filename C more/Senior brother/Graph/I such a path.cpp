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
vector<int> relateprimes[10000];
bool checked[10000];
int lvl[10000];
queue<int>que;

bool prime[10099];
void prime_factory(int n);

int prime_template(int surc,int ending);
int main()
{

    int i,j,k,m,n,val,t=0,test;
    int primes[9000];

    prime_factory(10000);
    ///sort the 4digit prime
    for(i=1000;i<10000;i++){
        if(prime[i]==0)primes[t++]=i;
    }
    ///push the related prime
    for(i=0;i<t;i++){
        for(j=0;j<t;j++){


            int dismatch_digit=0,digit=4,a=primes[i],b=primes[j];
            while(digit--){
                if((a%10)!=(b%10))dismatch_digit++;
                a=a/10;b=b/10;
            }
            if(dismatch_digit==1){
                relateprimes[primes[i]].push_back(primes[j]);
            }
        }
    }

    cin>>test;
    while(test--){
        scanf("%d %d",&m,&n);

        int cost=prime_template(m,n);
        printf("%d\n",cost);
        for(i=1000;i<10000;i++){
            checked[i]=false;
            lvl[i]=0;
        }
    }
    //free();   //if pointer array
    return 0;
}

int prime_template(int surc,int ending){
    if(surc==ending)return 0;
    checked[surc]=true;
    lvl[surc]=0;
    que.push(surc);
    while(!que.empty()){
        int n=que.front();

        que.pop();

        int len=relateprimes[n].size();
        for(int i=0;i<len;i++){
            int k=relateprimes[n][i];

            if(checked[k]==false){
                    que.push(k);
                checked[k]=true;

                lvl[k]=lvl[n]+1;

               // printf("%c %d\n",k+'A',lvl[k]);
                if(k==ending){
                   while(!que.empty()){
                    que.pop();
                   }

                    return lvl[k];
                }
            }

        }

    }

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

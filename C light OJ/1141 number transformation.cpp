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
vector<int>primeDivisorPlus[2000];
int level[2000];
bool checked[2000];
queue<int>que;
bool prime[1010];
int BFS(int node,int dest);

void prime_factory(int n);
int main()
{

    int i,j,k,m,n,val,t=0,test,total_prime=0;
    ///there are 95 prime number up to 1000.
    int primo[1001];
    prime_factory(1001);
    for(i=2;i<=1000;i++){
        if(prime[i]==0) primo[total_prime++]=i;
    }

    for(i=2;i<=1000;i++){

        for(j=0;j<total_prime && primo[j]<i;j++)  if(i%primo[j]==0) primeDivisorPlus[i].push_back(i+primo[j]);
    }
    cin>>n;
    while(n--){
        scanf("%d %d",&k,&m);
        printf("Case %d: %d\n",++t,BFS(k,m));

        for(i=0;i<=1000;i++){
            checked[i]=false;
            level[i]=0;
        }
    }
    //free();   //if pointer array
    return 0;
}

int BFS(int node,int dest){
    if(node==dest)return 0;
    checked[node]=true;
    level[node]=0;
    que.push(node);
    while(!que.empty()){
        int n=que.front();
        que.pop();
        int len=primeDivisorPlus[n].size();
        for(int i=0;i<len;i++){
            int val=primeDivisorPlus[n][i];

            if(val>dest)continue;

            if(checked[val]==false){
                checked[val]=true;
                level[val]=level[n]+1;

                if(val==dest){
                    while(!que.empty())que.pop();

                    return level[val];
                }
                que.push(val);

            }
        }

    }
    return -1;


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

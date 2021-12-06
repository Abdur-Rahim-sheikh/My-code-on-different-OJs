#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
int prime[1000000];
void prime_factory(int n);
int main()
{
    prime_factory(100005);
    int i,j,k,m,n,val,t=0,test,row[1000]={0},column[1000]={0},sum;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){

        for(j=0,sum=0;j<n;j++){
            scanf("%d",&val);
            int cp_val=val;;
            while(prime[val]!=0)val++;
            sum+=(val-cp_val);
            column[j]+=val-cp_val;
        }
        row[i]=sum;
    }
    sort(row,row+m);
    sort(column,column+n);
    printf("%d\n",min(row[0],column[0]));
    //free();   //if pointer array
    return 0;
}
// where is the prime in 2 to n and what(by index)
//returns zero if prime.
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

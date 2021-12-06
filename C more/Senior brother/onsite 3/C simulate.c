#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;


long long digits(int n,int base);
int main()
{

    int i,j,k,m,n,t=0,test,base;
    long long val;
    scanf("%d",&test);
    while(test--){
        scanf("%d %d",&n,&base);
        val=(long long)digits(n,base);
        printf("Case %d: %lld\n",++t,val);
    }

    //free();   //if polong longer array
    return 0;
}

long long digits(int n,int base)  ///keeper should be 10^7 for big value.
{
    long long counting;
    double sum;
	if(n==0 || n==1)
		return 1;
	else{

		for(counting=1,sum=0;counting<=n;counting++){
			sum+=log10(counting);
		}
		return (sum/log10(base))+1;
	}

}

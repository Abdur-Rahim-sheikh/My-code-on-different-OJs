#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cstdio>
using namespace std;


double keeper[1000099];
long long digits(int n,int base);
int main()
{

    int i,j,k,m,n[100000],t=0,test,base[100000];
    long long val;
    val=digits(1000000,10);
    scanf("%d",&test);
    for(i=0;i<test;i++){
        scanf("%d %d",&n[i],&base[i]);
    }
    while(test--){
        val=digits(n[t],base[t]);
        printf("Case %d: %lld\n",++t,val);
    }
    //free();   //if polong longer array
    return 0;
}


long long digits(int n,int base)  ///keeper should be 10^7 for big value.
{
	static int counto=1;
	if(n==0 || n==1)
		return 1;
	if(keeper[n]!=0)
		return keeper[n]/log10(base)+1;
	else{

		for(	;counto<=n;counto++){
			keeper[counto]=keeper[counto-1]+log10(counto);
		}
		return (keeper[n]/log10(base))+1;
	}

}

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
using namespace std;
int GCD(int m,int n);
int main()
{

    int i,j,k,m,n,val,t=0,test;
    scanf("%d %d",&m,&n);
    val=GCD(m,n);
    printf("%d",(m*n)/val);

    //free();   //if pointer array
    return 0;
}
int GCD(int m,int n)
{
	int divisor,divident,rem=1;
	divident=(m>n?m:n);
	divisor=(m>n?n:m);

	while(rem!=0)
	{
		rem=divident%divisor;
		divident=divisor;
		divisor=rem;
	}

	return divident;      //which  actually carrying divisor value

}

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
using namespace std;

int string_factorial(int n);
int main()
{

    double i,j,k,m,n,val,t=0,test,sum=1;
    int arr[1000];
    arr=string_factorial(10);
    reverse(arr,arr+8);
    for(i=0;i<8;i++)
        cout<<arr[i];

    //free();   //if pointer array
    return 0;
}
int string_factorial(int n){
	int total[1009],i,val,rem,t=0,j,carry,k,tem;
	total[0]=1;
	for(i=2;i<=n;i++){
		int fact[10][1000]={0};
		val=i;

		for(t=0;val>0;t++){
			rem=val%i;

			for(j=t,carry=0;total[j]!=[0];j++){
				fact[t][j]=(rem*total[t]+carry)%10;
				carry=(rem*total[t]+carry)/10;
			}
			val=val/10;
			if(val==0) fact[t][j]=carry;

		}
		///summing all multiples.
		for(k=0,carry=0;k<=j;k++){

			for(int l=0,tem=0;l<t;l++)tem+=fact[l][k];
			total[k]=(tem+carry)%10;
			carry=(tem+carry)/10;
		}
		total[k]=carry;
	}
	return total;

}

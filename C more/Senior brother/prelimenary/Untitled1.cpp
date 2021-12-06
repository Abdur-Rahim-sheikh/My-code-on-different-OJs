#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;
bool isPrime(int n);
int main()
{

    int i,j,k,m,n,val,t=0,test;
    while(scanf("%d",&n)){
        printf("%d is %d\n",n,isPrime(n));
    }
    //free();   //if pointer array
    return 0;
}
bool isPrime(int n)
{
	if (n == 1) {
		return false;
	} else if (n < 4) {
		return true;
	} else if (n % 2 == 0) {
		return false;
	} else if (n < 9) {
		return true;
	} else if (n % 3 == 0) {
		return false;
	} else {
		int r = floor(sqrt(n));
		int f = 5;
		while (f <= r) {
			if (n % f == 0) {
				return false;
			} else if (n % (f + 2) == 0) {
				return false;
			}
			cout<<f<<' '<<f+2<<endl;
			f += 6;
		}
		return true;
	}
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#define INF 1073741824
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;
    double a,b,c,d;
    cin>>test;
    while(test--){
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

        double k=abs(a-c);

        double s=(k+b+d)/2;

        double H= 2*sqrt(s*(s-k)*(s-d)*(s-b))/k;

        printf("Case %d: %0.8lf\n",++t,(a+c)*H/2);
    }

    //free();   //if pointer array
    return 0;
}

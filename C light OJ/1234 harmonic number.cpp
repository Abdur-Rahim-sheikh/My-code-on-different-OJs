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
#define K  0.5772156649
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,cnt=0,test;
    double sum=0;
    cin>>test;
    while(test--){
        scanf("%d",&n);
        sum=0;
        if(n<1000000){
            for(i=1;i<=n;i++){
                sum+=(1/(i*1.000));
            }
        }
        else sum=log(n)+K;

        printf("Case %d: %.10lf\n",++t,sum);
    }

    //free();   //if pointer array
    return 0;
}

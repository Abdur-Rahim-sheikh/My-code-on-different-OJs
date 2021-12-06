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
long long two_power(long long val){

    ll n=1;
    while(n*2-1<val) n=n*2;

    return n;

}
int main()
{

    ll i,j,k,m,n,val,t=0,cnt=0,test,twos;

    cin>>test;
    while(test--){
        scanf("%lld %lld",&m,&n);

        if(m-n==0)printf("0\n");
        else{
            val=abs(m-n);
            twos=two_power(val);
            cnt=0;
          // cout<<twos<<' '<<val<<endl;
            while(val){
                if(twos>val)twos=twos/2;
                else val=val-twos, cnt++;

            }

            printf("%lld\n",cnt);
        }
    }

    //free();   //if pointer array
    return 0;
}

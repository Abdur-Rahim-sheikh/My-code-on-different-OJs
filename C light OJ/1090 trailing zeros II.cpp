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

    int i,j,k,m,n,val,t=0,test,r,p,q,test_case=0;

    cin>>test;
    while(test--){
        scanf("%d %d %d %d",&n,&r,&p,&q);
        int cnt[4]={0},cnt_twos[4]={0},fives=5,twos=2;
        while(n/fives>0 ||(r/fives>0) || (n-r)/fives>0){     ///number of fives
            cnt[0]+=n/fives;                                 ///of n!,r!,(n-r)!
            cnt[1]+=r/fives;
            cnt[2]+=(n-r)/fives;
            fives*=5;
        }
        while(n/twos>0 || (r/twos>0) || (n-r)/twos>0){
            cnt_twos[0]+=n/twos;
            cnt_twos[1]+=r/twos;
            cnt_twos[2]+=(n-r)/twos;
            twos*=2;
        }

        ///adding trailing zeros of p q time if any;
        while(p%10==0){
            cnt[0]+=q;          ///for one zero of q will produce q zeros/five in total
            cnt_twos[0]+=q;     ///as well as q twos.
            p=p/10;

        }

         int cp_p=p;
         t=0;
        if(p%5==0){
            fives=5;

            while(cp_p%fives==0){
                t++;
                cp_p=cp_p/fives;
            }
        }
        cnt[0]+=(q*t);
       cp_p=p;
        t=0;
        if(cp_p%2==0){
            twos=2;
            while(cp_p%twos==0){
                t++;
                cp_p=cp_p/twos;
            }
        }
        cnt_twos[0]+=(q*t);

        ///after eliminating upper and lower twos minimum of upper 2twos and fives will produce
        ///trailing zeros.

        cnt_twos[0]=cnt_twos[0]-(cnt_twos[1]+cnt_twos[2]);
        cnt[0]=cnt[0]-(cnt[1]+cnt[2]);

        int sum=min(cnt[0],cnt_twos[0]);
        printf("Case %d: %d\n",++test_case,sum);

    }

    //free();   //if pointer array
    return 0;
}

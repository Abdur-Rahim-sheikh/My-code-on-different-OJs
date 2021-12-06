#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tgmath.h>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test,distance[1065],speed[1065];
    double mini,maxi,mid,sum,time,tem;
    while(scanf("%d",&n)!=EOF){
        scanf("%lf",&time);
        for(i=0,tem=1000000;i<n;i++){
            scanf("%d %d",&distance[i],&speed[i]);
            if(speed[i]<tem)tem=speed[i];
        }
       mini=-tem+0.0000001;
        maxi=1000000000;

        j=205;
        while(j--){
            mid=(mini+maxi)/2;

            for(i=0,sum=0;i<n;i++){
                sum+=(distance[i]/(double)(speed[i]+mid));
            }

            if(sum<time) maxi=mid;
            else mini=mid;
        }
        printf("%0.8lf\n",mid);
    }

    //free();   //if pointer array
    return 0;
}

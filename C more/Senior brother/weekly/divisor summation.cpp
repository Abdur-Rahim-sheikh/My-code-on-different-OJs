#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define ll long long
#define PI 2*acos(0.0)
using namespace std;

int main()
{

    int i,j,k,m,n,val,t=0,test;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&val);
        k=floor(sqrt(val));
        if(val==1)printf("0\n");
        else if(val<4)printf("1\n");
        else{
                int sum=0;
            for(i=2;i<=k;i++){
                if(val%i==0)sum+=(i+val/i);
            }
            if(k*k==val)sum-=k;
        printf("%d\n",sum+1);
        }
    }
    //free();   //if pointer array
    return 0;
}
